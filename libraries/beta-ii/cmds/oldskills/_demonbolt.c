#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_demonbolt(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
     if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_subclass() != "kataan" && tp->query_subclass() != "antipaladin")
      return notify_fail("What?\n");

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

   if (tp->query_level() < 6)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <demonbolt [living]>\n");

   if (ob == tp)
      return notify_fail("The demons laugh at you.\n");

   if (tp->query_mp() < 30) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = (tp->query_stats("wisdom")*7/8 + tp->query_skill("faith")/2);
   dmg -= (ob->query_stats("wisdom")/3 + ob->query_skill("magic defense")/4);
   if (dmg < 10) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+
      " sends the power of the demons at "+ob->query_cap_name()+"!",
      ({ ob, tp }));
   write("%^BOLD%^%^BLACK%^You send the power of the demons at "+
      ob->query_cap_name()+"!");
   tell_object(ob, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+
      " sends the power of the demons at your soul!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <demonbolt [living]>
Demonbolt sends a bolt of lightning-like power from the demons at
the caster's enemy.
");
}

int spell() {
   object o;
   o = this_player();

   if (o && (o->query_subclass() == "kataan" || o->query_subclass() == "antipaladin") && o->query_level() >= 6)
     return 1;
}


