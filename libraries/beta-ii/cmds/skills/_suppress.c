
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^RED%^"

#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

int catch_suppress(string);
int notify_suppress(object, object);
void end_suppress(class Effect);
void do_suppress(object, object);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 33*6 &&
      tp->query_skill("magic defense") >= 33*4)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <suppress [opponent]>\n\n"
    "This spell surrounds an opponent in a nearly invisible field "
    "of psionic power that will suppress his next spell.",
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
    FAIL("Suppress who?");

  if (tp == tgt)
    FAIL("Suppress your own magic?");

  if (tp->query_recast("suppress"))
    FAIL("Your powers will not work if spread so thin.");

  if (tgt->query_effect("suppress"))
    FAIL(capitalize(tgt->query_subjective())+
         " is already surrounded by a suppression field!");

  if (tp->query_mp() < 150)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_suppress(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object cmd;
  class Effect sup;

  if (!spell()) return;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (!(cmd = new(CMD_OB)))
    FAIL("An error occurred, please contact an immortal.");

  cmd->set_catchall(1);
  cmd->set_function(this_object(), "catch_suppress");
  cmd->set_notify("notify_suppress");

  sup = new(class Effect);
  sup->name = "suppress";
  sup->caster = tp;
  sup->castername = tp->query_name();
  sup->target = tgt;
  sup->desc = "You are surrounded by a psionic field of suppression.";
  sup->endtime = time() + 30;
  sup->endfunc = (: end_suppress :);
  // endmessages will only be displayed if spell wears off without firing
  sup->endmessages = ({
    COL+"The suppression field around you dissipates."+RES,
    COL+"The suppression field around "+tgt->query_cap_name()+" dissipates."+RES,
  });
  sup->misc = ({ cmd });

  cmd->move(tgt);
  tgt->add_effect(sup);

  tp->add_mp(-(100+random(50)));
  tp->set_recast("suppress", time()+45);

  message("magic", COL+"A psionic field of "+
                   COL2+"sup"+COL+"p"+COL2+"res"+COL+"s"+COL2+"ion"+COL+
                   " surrounds "+tgt->query_cap_name()+"."+RES, env, tgt);
  message("magic", COL+"A psionic field of "+
                   COL2+"sup"+COL+"p"+COL2+"res"+COL+"s"+COL2+"ion"+COL+
                   " surrounds you."+RES, tgt);

  return 1;
}

void end_suppress(class Effect sup) {
  mixed *info = sup->misc;
  object cmd = info[0];
  object caster = sup->caster;
  if (cmd) cmd->remove();
  if (caster) caster->set_recast_time("suppress", 0);
}

int notify_suppress(object killer, object victim) {
  class Effect *arr = victim->query_effects("suppress");
  foreach (class Effect sup in arr) {
    victim->remove_effect(sup);
  }
  if (sizeof(arr))
    return -1;
  else
    return 0;
}

// this_player() in this context is the person you cast suppress on
int catch_suppress(string str) {
  object tp = this_player();
  string verb = query_verb();
  class Effect sup = tp->query_effect("suppress");
  mixed *info = sup->misc;
  object caster, cmd;
  string path;

  // spell already fired and is just waiting for already-scheduled cleanup
  if (sizeof(info) == 2)
    return 0;

  // not suppressed anymore but cmd object is still there
  // this should never happen
  if (!sup) {
    // command _will_ fall through, command ob will remove itself afterward
    return -2;
  }

  // if the caster is gone, the spell should dissipate
  if (!(caster = sup->caster)) {
    // can't simply remove it - the command ob can't be removed while
    // it's processing something (which is what this func does)
    // call_out with time of 0 should work
    call_out( (: $(tp)->remove_effect($(sup)) :), 0);
    return -2;
  }

  if (path = CMD_D->find_cmd(verb, tp->query_search_path())) {
    path += ".c";
    if (file_size(path) > 0) {
      cmd = load_object(path);
      if (cmd) {
        if (function_exists("spell", cmd) != 0) {
          if (cmd->spell()) {
            do_suppress(tp, caster);
            sup->endmessages = 0;
            sup->misc = ({ cmd, 1 });
            // see above for why we can't simply remove this
            call_out( (: $(tp)->remove_effect($(sup)) :), 0);
            // command ob will not fall through and will remove itself
            return -1;
          }
        }
      }
    }
  }

  return 0;
}

void do_suppress(object victim, object caster) {
  object env = environment(victim);
  int dmg;

  message("magic", COL+"The field of magic around you crackles with power!\n"+
                   COL2+"Your spell shatters, the energies running wild "
                   "through your body!"+RES, victim);
  message("magic", COL+"The field of magic around "+victim->query_cap_name()+
                   " crackles, "+COL2+"shattering"+COL+" "+
                   victim->query_possessive()+" spell!"+RES, env, victim);

  if (environment(caster) != env)
    message("magic", COL+"You sense your suppression field around "+
                     victim->query_cap_name()+" "+COL2+"shatter"+COL+
                     " violently."+RES, caster);

  dmg = BALANCE3_D->get_damage(caster, victim, 3,
    ({ "psionics", "magic attack" }),
    ({ "intelligence" }),
    ({ "intelligence", "wisdom" }) );
  dmg = dmg * 35 / 100;

  victim->add_hp(-dmg);
  victim->add_mp(-(dmg / 2 + random(dmg/5)));

}

