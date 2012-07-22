//    Zerker attack.
//    By Nightshade.
//    rewritten by Nulvect
 
#include <std.h>
#include <dirs.h>

#define RAGE_OB "/cmds/skills/obj/rage_ob"
#define FAIL(s) return notify_fail(s)

inherit DAEMON;

int can_use(string ab);
/* to add more abilities into rage:
 * find the appropriate weapon type (or melee),
 * then add the ability into one of the arrays
 * based on what level it's received or how strong it is
 * pre-elite uses only low and med, elite uses med and high
 */
mapping abils = ([
  "melee" : ([
    "low":({"jab",}),
    "med":({"rush","headbutt"}),
    "high":({})
  ]),
  "blade" : ([
    "low":({"cut"}),
    "med":({"slash"}),
    "high":({"warblade"})
  ]),
  "axe" : ([
    "low":({"chop"}),
    "med":({"hack"}),
    "high":({"hew"}),
  ]),
  "blunt" : ([
    "low":({"bash"}),
    "med":({"maul"}),
    "high":({}),
  ]),
  "flail" : ([
    "low":({"whip"}),
    "med":({"lash"}),
    "high":({}),
  ]),
  "knife" : ([
    "low":({"stab"}),
    "med":({"puncture"}),
    "high":({}),
  ]),
  "projectile" : ([
    "low":({"pierce"}),
    "med":({"impale"}),
    "high":({}),
  ]),
  "ranged" : ([
    "low":({"shoot"}),
    "med":({}),
    "high":({}),
  ])
]);
mapping red_abils = ([
  "low":({"bite","claw","tailspear"}),
  "med":({"flameclaw","breathe"}),
  "high":({"fireshot","pyrestrike"})
]);

void help() {
  message("help",
    "Syntax: <rage>\n\n"
    "The ability of a berserker to fly into a fit of rage, "
    "enhancing the damage they can do. Some dragons have also been known to rage.",
    this_player());
}

int abil() {
  object r = this_player();
  if (r && r->query_level() >= 10 &&
      (r->query_subclass() == "berserker" || r->query_subclass() == "red"))
        return 1;
  return 0;
}

string type() { return "attack"; }

int can_cast(object tp) {
  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You can't rage as a ghost.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (environment(tp)->query_property("no attack"))
    FAIL("Greater powers prevent your malice.\n");


  if (tp->query_skill_bonus("attack"))
    FAIL("You are unable to bring yourself into a fury.\n");

  if (present("rage_ob_id",tp))
    FAIL("You are already raging!\n");

  return 1;
}
 
int cmd_rage(string str) {
  object tp=this_player();
  int elite=0;
  int attbonus=0, defbonus=0;
  int sp=100;
  int ferocity=1;
  string *types = ({});
  object rageob;
  mapping ab = ([]);

  if (!abil())
    return 0;
  
  if (!can_cast(tp))
    return 0;
  
  if (tp->query_sp() < 20)
    FAIL("You are too tired.\n");

  if (tp->query_level() >= 50) elite=1;

  types = ({"melee"});
  switch (tp->query_subclass()) {

    case "red":
      ferocity = (tp->query_skill("tail") +
                  tp->query_skill("claw") +
                  tp->query_skill("breath"))/3;
      ab["melee"] = ([]);
      if (elite) {
        ab["melee"]["low"] = filter(red_abils["med"], "can_use");
        ab["melee"]["high"] = filter(red_abils["high"], "can_use");
        attbonus= tp->query_level()*6;
        defbonus= -(tp->query_level());
      }
      else {  
        ab["melee"]["low"] = filter(red_abils["low"], "can_use");
        ab["melee"]["low"] += ab["melee"]["low"];
        ab["melee"]["high"] = filter(red_abils["med"], "can_use");
        ab["melee"]["high"] += ab["melee"]["high"];
        ab["melee"]["high"] += filter(red_abils["high"], "can_use");
        attbonus= tp->query_level()*24/5;
        defbonus= -(tp->query_level());
      }
    break;

    case "berserker":
      ferocity = tp->query_skill("ferocity");
      if (sizeof(tp->query_wielded()))
        types += tp->query_wielded()->query_type();
      if (elite) {
        foreach (string t in types) {
          ab[t] = ([]);
          ab[t]["low"] = filter(abils[t]["med"], "can_use");
          ab[t]["high"] = filter(abils[t]["high"], "can_use");
        }
        attbonus= tp->query_skill("rage");
        defbonus= -(tp->query_skill("rage")/6);
      }
      else {
        foreach (string t in types) {
          ab[t] = ([]);
          ab[t]["low"] = filter(abils[t]["low"], "can_use");
          ab[t]["low"] += ab[t]["low"];
          ab[t]["high"] = filter(abils[t]["med"], "can_use");
          ab[t]["high"] += ab[t]["high"];
          ab[t]["high"] += filter(abils[t]["high"], "can_use");
        }
        attbonus= tp->query_skill("rage")*4/5;
        defbonus= -(tp->query_skill("rage")/6);
      }
    break;

    default:
  }

  if (elite)
    sp = 200;
  else
    sp = 100;

  if (!objectp(rageob=new(RAGE_OB))) {
    message("info","An error occurred, please tell an immortal.",tp);
    return 1;
  }

  message("combat","You fly into a fit of rage!",tp);
  message("combat",tp->query_cap_name()+" flies into a fit of rage!",
    environment(tp), tp);
  
  rageob->move(tp);
  rageob->setup(tp, elite, types, ab, attbonus, defbonus, sp, ferocity);

  return 1;
}

int can_use(string ab) {
  string path = DIR_CLASS_CMDS+"/_"+ab;
  object cmd;
  if (file_size(path+".c") > 0 &&
      function_exists("abil", (cmd=load_object(path))) == path &&
      cmd->abil() == 1)
        return 1;
  return 0;
}

