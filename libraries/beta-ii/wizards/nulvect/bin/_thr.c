#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

mapping types = ([
  "none" : ([
    "color" : "%^BOLD%^%^BLUE%^",
    "verb" : "throw",
    "damagemod" : 0.7
  ]),
  "axe" : ([
    "color" : "%^BOLD%^%^RED%^",
    "verb" : "hurl",
    "damagemod" : 1.25,
    "stats": ({"strength"})
  ]),
  "blade" : ([
    "color" : "%^BOLD%^%^WHITE%^",
    "verb" : "heave",
    "damagemod" : 0.8,
    "stats": ({"strength"})
  ]),
  "blunt" : ([
    "color" : "%^ORANGE%^",
    "verb" : "fling",
    "damagemod" : 1
  ]),
  "flail" : ([
    "color" : "%^MAGENTA%^",
    "verb" : "fling",
    "damagemod" : 0.35
  ]),
  "knife" : ([
    "color" : "%^RED%^",
    "verb" : "throw",
    "damagemod" : 1.3,
    "stats": ({"dexterity"})
  ]),
  "projectile" : ([
    "color" : "%^YELLOW%^",
    "verb" : "hurl",
    "damagemod" : 1.1
  ]),
  "ranged" : ([
    "color" : "%^GREEN%^",
    "verb" : "chuck",
    "damagemod" : 0.5
  ])
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_level() >= 10 &&
      member_array(tp->query_class(), ({"fighter","rogue","wanderer"})) != -1)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <throw [what] (at [whom])>\n\n"
    "Allows you to throw something at an opponent to hurt him. "
    "Weapons are the most effective, of course.",
    this_player());
}

int can_cast(object tp, object tgt, object wep) {
  
  if (!tp) return 0;
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.\n");
  
  if (!wep)
    FAIL("Throw what?\n");

  if (!tgt)
    FAIL("Throw it at whom?\n");
  
  if (!living(tgt))
    FAIL("That would be pointless.\n");

  if (tp == tgt)
    FAIL("An ambitious attempt, but that's impossible.\n");
  
  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_objective()+" yet.\n");
  
  return 1;
}

int cmd_thr(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object wep;
  string wepname, tgtname;
  string type, verb, col, limb;
  string *skills, *stats;
  int dmg, cost;
  int rank, wc;

  if (!abil()) return 0;
  
  if (str) {
    if (sscanf(str, "%s at %s", wepname, tgtname) == 2) {
      wep = present(wepname, tp);
      tgt = present(tgtname, env);
    }
    else {
      wep = present(str, tp);
      tgt = tp->query_current_attacker();
    }
  }

  if (!can_cast(tp, tgt, wep)) return 0;

  if (wep->is_weapon()) {
    type = wep->query_type();
    wc = wep->query_wc();
  }
  else {
    type = "none";
    wc = 0;
  }

  rank = 1+tp->query_level()/16;
  if (rank > 4) rank=4;
  if (rank < 1) rank=1;
  
  skills = ({ "attack", "attack", type, type, "perception" });
  if (tp->query_skill("discipline"))
    skills += ({ "discipline" });
  if (tp->query_skill("ferocity"))
    skills += ({ "ferocity" });
  if (tp->query_skill("valor"))
    skills += ({ "valor" });
  if (tp->query_skill("murder"))
    skills += ({ "murder" });
  if (tp->query_skill("entertainment"))
    skills += ({ "entertainment" });

  stats = ({"strength", "dexterity"});
  if (member_array("stats", keys(types[type])) != -1)
    stats += types[type]["stats"];
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    stats,
    ({ "strength", "dexterity" }) );
    
  dmg += wc*7;

  dmg *= 1.15;

  dmg *= types[type]["damagemod"];

  if (tp->query_rest_type())
    dmg /= 2;

  cost = dmg/(10+rank);

  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->add_sp(-(cost+random(cost/10)));

  verb = types[type]["verb"];
  col = types[type]["color"];
  limb = tgt->return_target_limb();

  if (wep->is_weapon())
    wep->unequip();

  if (dmg < 2*(tgt->query_stats("dexterity")+tgt->query_skill("agility")/4)) {
    message("combat", "You "+verb+" your "+wep->query_name()+" at "+
                      tgt->query_cap_name()+" and miss completely.", tp);
    message("combat", tp->query_cap_name()+" "+verb+"s "+tp->query_possessive()+
                      " "+wep->query_name()+" at you and misses completely.", tgt);
    message("combat", tp->query_cap_name()+" "+verb+"s "+tp->query_possessive()+
                      " "+wep->query_name()+" at "+tgt->query_cap_name()+
                      " and misses completely.", env, ({tp,tgt}) );
    message("combat", "The "+wep->query_name()+" hits the ground.", env);
    wep->move(env);
  }
  else {
    message("combat", "You "+col+verb+RES+" your "+wep->query_name()+" at "+
                      tgt->query_cap_name()+" and "+col+"hit"+RES+" "+
                      tgt->query_objective()+" in the "+limb+"!", tp);
    message("combat", tp->query_cap_name()+" "+col+verb+"s"+RES+" "+
                      tp->query_possessive()+" "+wep->query_name()+" at you and "+
                      col+"hits"+RES+" your "+limb+"!", tgt);
    message("combat", tp->query_cap_name()+" "+col+verb+"s"+RES+" "+
                      tp->query_possessive()+" "+wep->query_name()+" at "+
                      tgt->query_cap_name()+" and "+col+"hits"+RES+" "+
                      tgt->query_objective()+" in the "+limb+"!", env, ({tp,tgt}) );

    tgt->do_damage(limb, dmg);

    if (wep->move(tgt) || random(100) < 20) {
      wep->move(env);
      message("combat", "The "+wep->query_name()+" falls to the ground.", env);
    }
  }

  return 1;
}
