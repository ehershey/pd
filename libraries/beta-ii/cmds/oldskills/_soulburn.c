#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_soulburn(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
    if (!str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_class() != "mage" || tp->query_subclass() != "necromancer")
      return notify_fail("What?\n");

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

   if (tp->query_level() < 50)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <shroud [living]>\n");

   if (tp->query_skill("necromancy") < 250)
      return notify_fail("Your skill of necromancy is not strong enough.\n");

   if (ob == tp)
      return notify_fail("You can't do that.\n");

   if (tp->query_mp() < 85) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

  if (ob->query_race() == "undead" || ob->query_race() == "lich")
      return notify_fail("This spell affects only those with souls.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("magic attack")/2 + tp->query_skill("necromancy");
   dmg += tp->query_stats("wisdom");
   dmg -= ob->query_stats("wisdom") + ob->query_skill("magic defense");
   dmg *= 3/2;
   if (dmg < 1) {
      write("Your spell fails.");
      tell_room(env, "%^MAGENTA%^"+tp->query_cap_name()+"'s spell fails.%^RESET%^", ({ tp }));
      return 1;
   }
   tell_room(env, "%^MAGENTA%^"+tp->query_cap_name()+" burns the soul of "+ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
   write("%^MAGENTA%^You burn the soul of "+ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^MAGENTA%^"+tp->query_cap_name()+" burns your soul causing you excrutiating pain!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <soulburn [victim]>
One of the most feared spells of necromancy, soulburn attacks the victims soul to which there is no known defense.  The spell however can not affect those without souls.
");
}

int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "necromancer" && o->query_level() >= 50)
     if (o->query_skill("necromancy") >= 250)
     return 1;
}