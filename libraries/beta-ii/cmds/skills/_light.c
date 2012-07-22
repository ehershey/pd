//      _light.c
//      Mage ability
//      created 011192 by Descartes of Borg
//      Totally redone by Valodin, Jan 15, 1993
//      Added the glowing orb part and the light_level part
//
//  recoded by Nulvect 2012-Feb-7

#include <std.h>
#include <dirs.h>
#include <effect_cl.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 RES+"%^ORANGE%^"

#define LIGHT_ORB DIR_CLASS_CMDS+"/obj/light_orb.c"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <light>\n"
    "\n"
    "This spell creates a glowing orb. It can be carried, "
    "or released to hover and brighten the area for everyone. "
    "The orb can also be extinguished when no longer needed.",
    this_player()
  );
}

int spell() {
  object tp = this_player();
  string *allowed = ({ "mage", "cleric", "druid", "white", "blue", });
  if (tp && tp->query_level() >= 3 &&
      (member_array(tp->query_class(), allowed) != -1 ||
      member_array(tp->query_subclass(), allowed) != -1))
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

  if (tp->query_effect("light"))
    FAIL("You already have a conjured light.");

  return 1;
}

int cmd_light(string str) {
  object tp = this_player();
  object orb;
  int max_light, time;
  class Effect light;

  // allows rooms and objects to let you "light" them
  if (str) return 0;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  message("magic", COL+"You conjure a glowing orb."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" conjures a glowing orb."+RES,
    environment(tp), tp);

  orb = new(LIGHT_ORB);
  if (!orb)
    FAIL("An error occurred, please contact a staff member.");

  max_light = BALANCE3_D->diminishing_returns(
    tp->query_skill("conjuring") + tp->query_stats("intelligence"), 0.07
  );
  if (max_light < 1)
    max_light = 1;

  time = BALANCE3_D->diminishing_returns(
    tp->query_skill("conjuring") + tp->query_stats("wisdom")*2, 100
  );
  time = time * 2;
  if (time < 120)
    time = 120;

  orb->set_max_light(to_int(max_light));
  orb->set_owner(tp);
  orb->move(tp);

  light = new(class Effect);
  light->name = "light";
  light->caster = tp;
  light->castername = tp->query_name();
  light->target = tp;
  light->desc = "You have conjured an orb of light.";
  light->endtime = time()+time;
  light->endfunc = function(class Effect l) {
    if (l->misc) l->misc->remove();
  };
  light->endmessages = ({
    COL2+"Your orb of light winks out of existence."+RES,
    COL2+tp->query_cap_name()+"'s orb of light winks out of existence."+RES
  });
  light->misc = orb;

  tp->add_effect(light);
  tp->add_skill_points("conjuring", 10);
  tp->add_mp(-(7+random(4)));
  tp->set_magic_round(1);

  return 1;
}

