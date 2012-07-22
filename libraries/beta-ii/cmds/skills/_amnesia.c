
#include <std.h>
#include <effect_cl.h>
#include <dirs.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 RES+"%^MAGENTA%^"

#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

int catch_amnesia(string);
int notify_amnesia(object, object);
void end_amnesia(class Effect);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 27 * 6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <amnesia [victim]>\n\n"
    "This psionics spell will scramble your enemy's mind, causing him to "
    "forget several spells and abilities.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers in this state.");

  if (!tgt)
    FAIL("Cast amnesia upon whom?");

  if (tp == tgt)
    FAIL("That would be unwise.");

  if (tgt->query_effect("amnesia"))
    FAIL(capitalize(tgt->query_subjective())+
	 " is already afflicted with amnesia!");

  if (tp->query_mp() < 100)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_amnesia(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, howmany, cost;
  class Effect am;
  object cmd;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  time = 10;
  time += tp->query_stats("wisdom")/2;
  time += tp->query_skill("conjuring")/4;
  time -= tgt->query_stats("wisdom") * 80 / 100;
  if (time < 10) time = 10;

  howmany = 1 + random(2);
  howmany += (tp->query_stats("intelligence")-50)/40;
  howmany += (tp->query_skill("psionics")-160)/60;
  howmany -= tgt->query_skill("magic defense") / 30;

  if (howmany > 4)
    howmany = 4;
  if (howmany < 1)
    howmany = 1;

  cost = 150 + time*3 + howmany*40 + random(20);
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  if (!(cmd = new(CMD_OB)))
    FAIL("An error occurred, please contact a staff member.");

  cmd->set_catchall(1);
  cmd->set_function(this_object(), "catch_amnesia");
  cmd->set_notify("notify_amnesia");

  am = new(class Effect);
  am->name = "amnesia";
  am->caster = tp;
  am->castername = tp->query_name();
  am->target = tgt;
  am->desc = "You seem to have forgotten some of your abilities.";
  am->endtime = time() + time;
  am->endfunc = (: end_amnesia :);
  am->endmessages = ({
    COL+"Your memory finally comes back to you."+RES,
    COL+tgt->query_cap_name()+" seems to remember something."+RES,
  });
  am->misc = ({ cmd, howmany, ([]) });

  cmd->move(tgt);
  tgt->add_effect(am);

  tp->add_mp(-cost);
  tp->set_magic_round(1);

  message("magic", COL+"You cast a "+COL2+"chaotic"+COL+" barrage of psionic "+
                   COL2+"energy"+COL+" into "+tgt->query_cap_name()+"'s mind!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" casts a "+COL2+"chaotic"+
                   COL+" barrage of psionic "+
                   COL2+"energy"+COL+" into your mind!"+RES, tgt);
  message("magic", COL+tp->query_cap_name()+" casts a "+COL2+"chaotic"+
                   COL+" barrage of psionic "+
                   COL2+"energy"+COL+" into "+tgt->query_cap_name()+"'s mind!"+RES,
		   env, ({ tp, tgt }) );

  message("magic", COL2+"Your memory is scrambled!"+RES, tgt);
  message("magic", COL2+tgt->query_cap_name()+"'s memory is scrambled!"+RES,
                   env, tgt);

  return 1;
}

void end_amnesia(class Effect am) {
  mixed *info = am->misc;
  object cmd = info[0];
  if (cmd) cmd->remove();
}

int notify_amnesia(object killer, object victim) {
  class Effect am = victim->query_effect("amnesia");
  if (am) {
    victim->remove_effect(am);
    return -1;
  }
  else
    return 0;
}

int catch_amnesia(string str) {
  object tp = this_player();
  string verb = query_verb();
  class Effect am = tp->query_effect("amnesia");
  mixed *info;
  int howmany;
  mapping check;
  object cmd;
  string path;
  int catch_it = 0;

  if (!am) return -2;

  info = am->misc;
  howmany = info[1];
  check = info[2];

  if (check[verb] == 1)
    catch_it = 1;

  else if (check[verb] == 0 && !nullp(check[verb]))
    catch_it = 0;

  else if (howmany < 1)
    catch_it = 0;

  else if (path = CMD_D->find_cmd(verb, tp->query_search_path())) {
    path += ".c";
    if (file_size(path) > 0) {
      cmd = load_object(path);
      if (cmd) {
	if ((function_exists("spell", cmd) != 0 && cmd->spell()) ||
	    (function_exists("abil", cmd) != 0 && cmd->abil())) {
	      if (random(1000) > 350) {
		howmany--;
		check[verb] = 1;
		catch_it = 1;
	      }
	      else {
		check[verb] = 0;
		catch_it = 0;
	      }
	}
      }
    }
  }

  info[1] = howmany;
  info[2] = check;
  am->misc = info;

  if (catch_it) {
    message("info", "You can't quite remember how to do that.", tp);
    return 1;
  }

  return 0;
}

