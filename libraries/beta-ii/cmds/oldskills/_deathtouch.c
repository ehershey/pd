#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_deathtouch(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_casting()) return 1;
   if (tp->query_disable()) return notify_fail("You are busy.\n");
   if (tp->query_skill("necromancy") < 100)
      return notify_fail("You lack the skill in necromancy.\n");
   if (tp->query_skill("magic attack") < 100)
     return notify_fail("Your powers of attack are not yet strong enough.\n");
   if (tp->query_subclass() != "necromancer")
      return notify_fail("What?\n");
   if (tp->query_level() < 20)
      return notify_fail("You are not high enough to cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob) || ob->query_race() == "undead" || ob->query_race() == "lich")
return notify_fail("Deathtouch may only be cast upon the living.\n");
   if (ob == tp)
      return notify_fail("That is not possible.\n");
   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("necromancy")*3/2 + tp->query_stats("wisdom");
   dmg += tp->query_skill("magic attack");
   dmg -= ob->query_skill("magic defense")/3 + ob->query_skill("wisdom")/2;
 dmg -= ob->query_stats("constitution")/2;
   dmg *= 2;
   if (dmg < 10) {
      write("Your spell fails!");
      tell_room(env, ""+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^BLACK%^"+tp->query_cap_name()+" touches "+ob->query_cap_name()+" with a %^GREEN%^glowing%^BLACK%^ finger!\n", ({ tp }));
   write("%^BOLD%^BLACK%^You touch "+ob->query_cap_name()+" with your %^GREEN%^glowing%^BLACK%^ finger!");
   tell_room(env, "%^BOLD%^BLACK%^"+ob->query_cap_name()+" cringes from the touch of death!", ({ ob, tp }));
   tell_object(ob, "%^BOLD%^BLACK%^"+tp->query_cap_name()+" sends death's painful touch through your body!\nYou feel weak.");
   write("%^BOLD%^BLACK%^Your touch causes "+ob->query_cap_name()+" great damage!");
    tp->add_mp(-dmg/7);
    ob->add_sp(-(dmg/40));
    tp->set_casting(dmg*2/5);
    tp->set_disabled();
   return 1;
}
void help() {
write("
Syntax: <deathtouch [living target]>
The spell used by necromancers that causes the victim to feel the touch of death.  The spell causes great damage and leaves the target drained.
");
}
int spell() {
   object o;
   o = this_player();
   if (o)
  if (o->query_subclass() == "necromancer")
     if (o->query_skill("necromancy") >= 100 && o->query_level() >= 20 && o->query_skill("magic attack") >= 100)
      return 1;
}
