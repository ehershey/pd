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
 * pre-elite uses low:med:med:high, elite uses med:high
 */
mapping abils = ([
  "melee" : ([
    "low":({"jab"}),
    "med":({"headbutt","pummel"}),
    "high":({})
  ]),
  "blade" : ([
    "low":({}),
    "med":({"slash"}),
    "high":({"warblade"})
  ]),
  "axe" : ([
    "low":({}),
    "med":({"hack"}),
    "high":({"hew"}),
  ]),
  "blunt" : ([
    "low":({}),
    "med":({"bash"}),
    "high":({}),
  ]),
  "flail" : ([
    "low":({}),
    "med":({"whip"}),
    "high":({}),
  ]),
  "knife" : ([
    "low":({}),
    "med":({"stab"}),
    "high":({}),
  ]),
  "projectile" : ([
    "low":({}),
    "med":({"impale"}),
    "high":({}),
  ]),
  "ranged" : ([
    "low":({}),
    "med":({"shoot"}),
    "high":({}),
  ])
]);
mapping red_abils = ([
  "low":({"bite","claw","tailwhip"}),
  "med":({"flameclaw","breathe"}),
  "high":({"fireshot","pyrestrike"})
]);
string *racial_abils = ({
  "gore",
  "levin"
});

void help() {
  message("help",
    "Syntax: <rage>\n\n"
    "The ability of a berserker to fly into a fit of rage, "
    "enhancing the damage they can do. Some dragons have also been known to rage.\n\n"
    "%^BOLD%^%^RED%^Warning:%^RESET%^ You cannot control your actions while raging!",
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
    FAIL("You can't rage as a ghost.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("Greater powers prevent your malice.\n");


  if (tp->query_skill_bonus("attack"))
    FAIL("You are unable to bring yourself into a rage.\n");

  if (present("rage_ob_id",tp))
    FAIL("You are already raging!\n");

  return 1;
}
 
int cmd_rage(string str) {
  object tp=this_player();
  int elite=0;
  int attbonus=0, defbonus=0;
  int sp;
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
  sp = tp->query_max_sp()/2;
  if (sp < 200) sp=200;

  types = ({"melee"});
  switch (tp->query_subclass()) {

    case "red":
      /*
      ferocity = (tp->query_skill("tail") +
                  tp->query_skill("claw") +
                  tp->query_skill("breath"))/3;
      */
      ferocity = tp->query_skill("ferocity");
      ab["melee"] = ([]);
      if (elite) {
        ab["melee"]["low"] = filter(red_abils["med"], "can_use");
        ab["melee"]["high"] = filter(red_abils["high"], "can_use");
        attbonus= tp->query_level()*12;
        defbonus= -(tp->query_level()*2);
      }
      else {  
        ab["melee"]["low"] = filter(red_abils["low"], "can_use");
        //ab["melee"]["low"] += ab["melee"]["low"];
        ab["melee"]["high"] = filter(red_abils["med"], "can_use");
        ab["melee"]["high"] += ab["melee"]["high"];
        ab["melee"]["high"] += filter(red_abils["high"], "can_use");
        attbonus= tp->query_level()*48/5;
        defbonus= -(tp->query_level()*2);
      }
    break;

    case "berserker":
      ferocity = tp->query_skill("ferocity");
      if (sizeof(tp->query_wielded()))
        types += tp->query_wielded()->query_type();
      ab["racial"] = filter(racial_abils, "can_use");
      if (elite) {
        foreach (string t in types) {
          ab[t] = ([]);
          ab[t]["low"] = filter(abils[t]["med"], "can_use");
          ab[t]["high"] = filter(abils[t]["high"], "can_use");
        }
        attbonus= tp->query_skill("rage")*2;
        defbonus= -(tp->query_skill("rage")/3);
      }
      else {
        foreach (string t in types) {
          ab[t] = ([]);
          ab[t]["low"] = filter(abils[t]["low"], "can_use");
          //ab[t]["low"] += ab[t]["low"];
          ab[t]["high"] = filter(abils[t]["med"], "can_use");
          ab[t]["high"] += ab[t]["high"];
          ab[t]["high"] += filter(abils[t]["high"], "can_use");
        }
        attbonus= tp->query_skill("rage")*8/5;
        defbonus= -(tp->query_skill("rage")/3);
      }
    break;

    default:
  }

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
      objectp(cmd=load_object(path)) &&
      (cmd->abil() || cmd->spell()))
        return 1;
  return 0;
}

