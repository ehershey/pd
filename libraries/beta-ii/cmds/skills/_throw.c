#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

mapping types = ([
  "none" : ([
    "color" : "%^BOLD%^%^BLUE%^",
    "verb" : "throw",
    "damagemod" : 0.3,
    "dtype" : DAMAGE_IMPACT,
    "dflags" : DAMAGE_NO_SEVER,
  ]),
  "axe" : ([
    "color" : "%^BOLD%^%^RED%^",
    "verb" : "hurl",
    "damagemod" : 1.05,
    "stats": ({"strength"}),
    "dtype" : DAMAGE_IMPACT | DAMAGE_SLASH,
  ]),
  "blade" : ([
    "color" : "%^BOLD%^%^WHITE%^",
    "verb" : "heave",
    "damagemod" : 0.7,
    "stats": ({"strength"}),
    "dtype" : DAMAGE_SLASH | DAMAGE_PIERCE,
  ]),
  "blunt" : ([
    "color" : "%^ORANGE%^",
    "verb" : "fling",
    "damagemod" : 0.9,
    "dtype" : DAMAGE_IMPACT,
  ]),
  "flail" : ([
    "color" : "%^MAGENTA%^",
    "verb" : "fling",
    "damagemod" : 0.35,
    "dtype" : DAMAGE_IMPACT,
    "dflags" : DAMAGE_NO_SEVER,
  ]),
  "knife" : ([
    "color" : "%^RED%^",
    "verb" : "throw",
    "damagemod" : 1.1,
    "stats": ({"dexterity"}),
    "dtype" : DAMAGE_PIERCE,
    "dflags" : DAMAGE_NO_SEVER,
  ]),
  "projectile" : ([
    "color" : "%^YELLOW%^",
    "verb" : "hurl",
    "damagemod" : 1.0,
    "dtype" : DAMAGE_PIERCE,
    "dflags" : DAMAGE_NO_SEVER,
  ]),
  "ranged" : ([
    "color" : "%^GREEN%^",
    "verb" : "chuck",
    "damagemod" : 0.5,
    "dtype" : DAMAGE_IMPACT,
    "dflags" : DAMAGE_NO_SEVER,
  ])
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_level() >= 10 &&
      member_array(tp->query_class(), ({"fighter","rogue","wanderer"})) != -1)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <throw [what] (at [whom])>\n\n"
    "Allows you to throw something at an opponent to hurt him. "
    "Weapons are the most effective, of course, and some types of weapons are better than others.",
    this_player());
}

int can_cast(object tp, object tgt, object wep) {
  
  if (!tp) return 0;
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
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

int cmd_throw(string str) {
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
    wc = 13-absolute_value(9-wep->query_weight());
    if (wc < 3) wc = 3;
    if (wc > 13) wc = 13;
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

  dmg *= 0.9;

  dmg *= types[type]["damagemod"];

  if (tp->query_rest_type())
    dmg /= 2;

//  cost = dmg/(10+rank);
  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * (140 - (rank*10)) / 100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->add_sp(-(cost+random(cost/10)));
  tp->set_disable();

  if (sizeof(wep->query_name()))
    wepname = wep->query_name();
  else
    wepname = wep->query_short();
  verb = types[type]["verb"];
  col = types[type]["color"];
  limb = tgt->return_target_limb();

  if (wep->is_weapon())
    wep->unequip();

  if (dmg < 2*(tgt->query_stats("dexterity")+tgt->query_skill("agility")/4)) {
    message("combat", "You "+verb+" your "+wepname+" at "+
                      tgt->query_cap_name()+" and miss completely.", tp);
    message("combat", tp->query_cap_name()+" "+verb+"s "+tp->query_possessive()+
                      " "+wepname+" at you and misses completely.", tgt);
    message("combat", tp->query_cap_name()+" "+verb+"s "+tp->query_possessive()+
                      " "+wepname+" at "+tgt->query_cap_name()+
                      " and misses completely.", env, ({tp,tgt}) );
    message("combat", "The "+wepname+" hits the ground.", env);
    wep->move(env);
  }
  else {
    message("combat", "You "+col+verb+RES+" your "+wepname+" at "+
                      tgt->query_cap_name()+" and "+col+"hit"+RES+" "+
                      tgt->query_objective()+" in the "+limb+"!", tp);
    message("combat", tp->query_cap_name()+" "+col+verb+"s"+RES+" "+
                      tp->query_possessive()+" "+wepname+" at you and "+
                      col+"hits"+RES+" your "+limb+"!", tgt);
    message("combat", tp->query_cap_name()+" "+col+verb+"s"+RES+" "+
                      tp->query_possessive()+" "+wepname+" at "+
                      tgt->query_cap_name()+" and "+col+"hits"+RES+" "+
                      tgt->query_objective()+" in the "+limb+"!", env, ({tp,tgt}) );

    tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | types[type]["dtype"], types[type]["dflags"], tp);

    if (wep->move(tgt) || random(100) < 20) {
      wep->move(env);
      message("combat", "The "+wepname+" falls to the ground.", env);
    }
  }

  tp->add_skill_points(type, 10+random(tp->query_level()));

  return 1;
}
