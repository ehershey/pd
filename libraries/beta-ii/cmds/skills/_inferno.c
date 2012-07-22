#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 30*6 &&
      tp->query_skill("magic attack") >= to_int(30*5.5) )
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <inferno>\n\n"
    "This pyromancer spell fills the area with a blazing inferno which "
    "burns everyone within range.",
    this_player());
}

int can_cast(object tp) {
  object env;
  
  if (!tp) return 0;
  
  env = environment(tp);

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  return 1;
}

int cmd_inferno(string str) {
  object tp=this_player();
  object env;
  object *tgts;
  object *ptgts;
  string party;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  env = environment(tp);
  party = tp->query_party();
  
  tgts = filter(all_inventory(env), (: $1->is_living() :) );
  tgts -= ({tp});

  tp->add_mp(-(20+random(20)));
  tp->set_magic_round();
  tp->set_paralyzed(1, "You are concentrating on your spell.");

  message("magic",COL+"You create a raging inferno!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" creates a raging inferno!"+RES,
    env, tp);

  foreach (object tgt in tgts) {
    int cost, dmg;

    if (userp(tgt) && !interactive(tgt)) {
      message("info", "You cannot attack link-dead players.", tp);
      continue;
    }
    
    if (!(tp->kill_ob(tgt))) {
      message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
      continue;
    }
    
    dmg = BALANCE3_D->get_damage(tp, tgt, 3,
      ({"pyromancy", "pyromancy", "magic attack", "conjuring"}),
      ({"intelligence", "intelligence", "intelligence", "wisdom"}),
      ({"pyromancy", "magic attack"}) );
    dmg = dmg*7/10;
    
    cost = BALANCE3_D->get_cost(dmg, 3, "mp") * 95 / 100;

    if (tp->query_mp() < cost) {
      message("info", "You run out of energy to keep the inferno blazing.", tp);
      break;
    }

    if (dmg < 30) {
      message("magic", COL+"The inferno blazes harmlessly around you."+RES, tgt);
      message("magic", COL+"The inferno blazes harmlessly around "+
        tgt->query_cap_name()+"."+RES, env, tgt);
      continue;
    }

    tp->add_mp(-(cost+random(cost/10)));

    message("magic", COL+"The flaming inferno b%^WHITE%^l%^RED%^a%^WHITE%^z%^RED%^e%^WHITE%^s%^RED%^ fiercely and burns you!"+RES, tgt);
    message("magic", COL+"The flaming inferno b%^WHITE%^l%^RED%^a%^WHITE%^z%^RED%^e%^WHITE%^s%^RED%^ fiercely and burns "+
      tgt->query_cap_name()+"!"+RES, env, tgt);
    
    tgt->do_damage("random", dmg, DAMAGE_MAGIC | DAMAGE_FIRE, 0, tp);
    
  }

  return 1;
}
