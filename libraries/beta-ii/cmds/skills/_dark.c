//      _dark.c
//      Mage ability
//      Created by Valodin, Jan 16, 1993
//  recoded by Nulvect 2012-Feb-11, based on new light spell

#include <std.h>
#include <dirs.h>
#include <effect_cl.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 RES+"%^MAGENTA%^"

#define DARK_ORB DIR_CLASS_CMDS+"/obj/dark_orb.c"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <dark>\n"
    "\n"
    "This spell creates an orb of darkness. It can be carried, "
    "or released to hover and absorb light from the entire area. "
    "The orb can also be shattered when no longer needed.",
    this_player()
  );
}

int spell() {
  object tp = this_player();
  string *allowed = ({
    "illusionist", "conjurer", "necromancer", "wizard", "black"
  });
  if (tp && tp->query_level() >= 5 &&
      member_array(tp->query_subclass(), allowed) != -1)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your magic fails.");

  if (tp->query_mp() < 10)
    FAIL("Too low on magic power.");

  if (tp->query_effect("dark"))
    FAIL("You already have an orb of darkness.");

  return 1;
}

int cmd_dark(string str) {
  object tp = this_player();
  object orb;
  int max_dark, time;
  class Effect dark;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  message("magic", COL+"You conjure an orb of darkness."+RES, tp);
  message("magic", COL+tp->query_cap_name()+
    " conjures an orb of darkness."+RES,
    environment(tp), tp);

  orb = new(DARK_ORB);
  if (!orb)
    FAIL("An error occurred, please contact a staff member.");

  max_dark = BALANCE3_D->diminishing_returns(
    tp->query_skill("conjuring") + tp->query_stats("intelligence"), 0.25
  );
  max_dark = max_dark * -1;
  if (max_dark > -1)
    max_dark = -1;

  time = BALANCE3_D->diminishing_returns(
    tp->query_skill("conjuring") + tp->query_stats("wisdom")*2, 100
  );
  time = time * 2;
  if (time < 100)
    time = 100;

  orb->set_max_dark(to_int(max_dark));
  orb->set_owner(tp);
  orb->move(tp);

  dark = new(class Effect);
  dark->name = "dark";
  dark->caster = tp;
  dark->castername = tp->query_name();
  dark->target = tp;
  dark->desc = "You have conjured an orb of darkness.";
  dark->endtime = time()+time;
  dark->endfunc = function(class Effect l) {
    if (l->misc) l->misc->remove();
  };
  dark->endmessages = ({
    COL2+"Your orb of darkness shatters and disintegrates."+RES,
    COL2+tp->query_cap_name()+"'s orb of darkness shatters."+RES
  });
  dark->misc = orb;

  tp->add_effect(dark);
  tp->add_skill_points("conjuring", 10);
  tp->add_mp(-(7+random(4)));
  tp->set_magic_round(1);

  return 1;
}

