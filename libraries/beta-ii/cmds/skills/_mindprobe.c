
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

string *magic_classes = ({
  "mage", "elementalist", "clergy"
});
string *magic_subs = ({
  "gypsy", "paladin", "antipaladin",
  "black", "blue", "white",
});

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_level() >= 8)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <mindprobe [who]>\n\n"
    "Allows a sorceror to probe the magical abilities of "
    "a living thing.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers while dead.");

  if (!tgt)
    FAIL("Probe whose mind?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Why bother?");

  if (tp->query_mp() < 25)
    FAIL("Too low on magic.");

  return 1;
}

string query_examine(object tp, object tgt) {
  int psi = tp->query_skill("psionics");
  string ret;
  string *spells;
  string cl, sub;
  int ma, md, intel, wis, level, tmp;
  
  cl = tgt->query_class();
  sub = tgt->query_subclass();
  level = tgt->query_level();
  ma = tgt->query_skill("magic attack");
  md = tgt->query_skill("magic defense");
  intel = tgt->query_stats("intelligence");
  wis = tgt->query_stats("wisdom");
  tmp = ma + md;

  ret = COL+tgt->query_cap_name()+" seems to be ";

  if (member_array(cl, magic_classes) != -1 ||
      member_array(sub, magic_subs) != -1) {
        ret += "very skilled with magic.";
  }
  else if ( (level < 20 && tmp+(intel+wis)/2 >= ( (3+3+3) * level) ) ||
            (level >= 20 && tmp+intel+wis >= ( (3+3+3) * level ) ) ) {
    ret += "slightly magically oriented.";
  }
  else {
    ret += "unskilled in the magical arts.";
  }

  ret += RES;

  if (psi >= 25*6 && tgt->is_monster()) {
    spells = tgt->query_spells();

    // only look at spells, not abilities, which are also in this list to start
    spells = filter(spells, function(string spell, object tgt) {
      string *paths = tgt->query_search_path();
      string file = CMD_D->find_cmd(spell, paths);
      object cmd;
      if (!file) return 0;
      file += ".c";
      if (file_size(file) < 1) return 0;
      cmd = load_object(file);
      if (!cmd) return 0;
      if (!function_exists("spell", cmd)) return 0;
      return 1;
    }, tgt);

    if (spells && sizeof(spells)) {
      ret += "\n"+COL2+capitalize(tgt->query_subjective());
      ret += " knows how to cast "+list(spells)+".";
    }
    else if (sub != "none") {
      ret += "\n"+COL2+capitalize(tgt->query_subjective());
      ret += " is "+indefinite_article(sub)+(cl == "dragon" ? " "+cl : "")+".";
    }
  }

  ret += RES;

  tp->add_mp(-(10+random(10)));

  return ret;
}

int cmd_mindprobe(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  message("magic", COL+"You send a thread of power to probe into "+
    tgt->query_cap_name()+"'s mind."+RES, tp);

  tp->set_magic_round(1);
  tp->add_mp(-15);

  call_out("finish_mindprobe", 2, ({ tp, tgt }) );

  return 1;
}

void finish_mindprobe(mixed *args) {
  object tp = args[0];
  object tgt = args[1];

  if (!tp) return;

  if (!tgt) {
    message("magic", "Your spell fails.", tp);
    return;
  }

  message("magic", query_examine(tp, tgt), tp);

  if (tgt->query_stats("wisdom") + tgt->query_skill("perception") >
      tp->query_stats("intelligence") + tp->query_skill("psionics")/2)
        message("magic",
          "You sense a magical presence probing your mind.", tgt);

}
