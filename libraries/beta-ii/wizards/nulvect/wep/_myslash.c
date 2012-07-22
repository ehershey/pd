#include <std.h>
#include <daemons.h>

#define TYPE "blade"
#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"
#define BALANCE3_D "/daemon/balance3_d"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill(TYPE) >= 100 && tp->query_skill("attack") >= 40)
    return 1;
  return 0;
}

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use a sword for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_myslash(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int cost, dmg, rank;
  int wc;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  foreach (object w in weps)
    wc += w->query_wc();
  wc = wc / sizeof(weps);
  
  if (tp->query_skill(TYPE) >= 160) rank=3;
  else rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, "attack" }),
        ({ "strength", "dexterity" }),
        ({ "strength", "dexterity" }) );
  
  dmg += wc*4;

  if (dmg > 600) dmg=600+random(tp->query_level()*2);
  
  cost=dmg/10;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();
  if (dmg < 50) {
    message("combat","You slash at "+tgt->query_cap_name()+" with "+wep+
                     " and miss.", tp);

    message("combat",tp->query_cap_name()+" slashes at "+tgt->query_cap_name()+
                     " with "+wep+" and misses.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" slashes at you with "+wep+" and misses.", tgt);
  }
  else {
    message("combat","You "+COL+"slash"+RES+" "+tgt->query_cap_name()+
                     " in the "+limb+" with "+wep+"!", tp);
    
    message("combat",tp->query_cap_name()+" "+COL+"slashes"+RES+
                     " you in the "+limb+" with "+wep+"!", tgt);

    message("combat",tp->query_cap_name()+" "+COL+"slashes"+RES+" "+
                     tgt->query_cap_name()+" in the "+limb+" with "+
                     " "+wep+"!", environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(limb, dmg);

    if (rank == 3 && tp->query_stats("dexterity")+random(30) > 60) {
      message("combat","You quickly swing around and "+COL+"slash"+RES+" "+
                       tgt->query_objective()+" again!",tp);
      message("combat",tp->query_cap_name()+" quickly swings around and "+
                       COL+"slashes"+RES+" you again!", tgt);
      message("combat",tp->query_cap_name()+" quickly swings around and "+
                       COL+"slashes"+RES+" "+tgt->query_objective()+" again!",
                       environment(tp), ({tp, tgt}) );
      tgt->do_damage(limb, dmg/8);
    }
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <slash [living]>\n\n"
    "This is an intermediate sword move. Faster users can "
    "even get in a second hit.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

