
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 12*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <wound [living]>\n\n"
    "A cleric spell which damages the target and re-opens existing wounds, "
    "causing extra blood loss.",
    this_player());
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("Wound whom?\n");

  if (!living(tgt))
    FAIL("That isn't alive.\n");

  if (tp == tgt)
    FAIL("Ouch.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");

  if (tgt->query_hp() > tgt->query_max_hp()*7/10)
    FAIL(capitalize(tgt->query_subjective())+
         " has no wounds you can reopen.\n");
  
  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_cap_name()+".\n");
  
  return 1;
}

int cmd_wound(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int i;
  int dmg, cost;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({"healing", "healing", "belief"}),
    ({"wisdom", "wisdom", "intelligence"}),
    ({"wisdom"}) );

  if (tgt->query_hp() > tgt->query_max_hp()/3)
    dmg = dmg*3/4;
  else
    dmg = dmg*5/4;

  cost = BALANCE3_D->get_cost(dmg, 2, "mp");
  
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  tp->add_mp(-(cost+random(cost/7)));
  tp->set_magic_round();

  message("magic", "You point at "+tgt->query_cap_name()+".",tp);
  message("magic", tp->query_cap_name()+" points at you.", tgt);
  message("magic", tp->query_cap_name()+" points at "+tgt->query_cap_name()+
                   ".", env, ({tp, tgt}) );
  message("magic", COL+"Your wounds "+COL2+"open"+RES+COL+" "
                   "and "+COL2+"blee"+RES+COL+"d!"+RES, tgt);
  message("magic", COL+tgt->query_cap_name()+"'s wounds "+
                   COL2+"open"+RES+COL+" and "+
                   COL2+"blee"+RES+COL+"d!"+RES, env, tgt);

  if (random(100) > 70)
    tp->add_alignment(-1);

  tgt->do_damage("none", dmg, DAMAGE_FAITH, 0, tp);

  return 1;
}

