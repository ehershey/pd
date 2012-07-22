// /cmds/skills/_flick.c
// ::Inferno(11/18/2000);
//  Fix by Whit Jan 4, 2002
//  Old file in /wizards/whit/fixed/old/_flick.c
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_flick(string str) {
   int dmg, x;
   string type, who;
//   object ob, *weapons, env;
   object ob, env;
   if (!abil())
    return notify_fail("What?\n");
   if (!str) return notify_fail("Syntax: <flick [currency] at [who]>\n");
   if (sscanf(str, "%s at %s", type, who) != 2) type = str;
   switch(type) {
     case "platinum": x = 30; break;
     case "gold":     x = 20; break;
     case "electrum": x = 10; break;
     case "silver":   x = 5; break;
     case "copper":   x = 1; break;
     default: if (this_player()->query_money(type)) x = 10;
              else return notify_fail("Syntax: <flick [currency] at [who]>\n");
   }
   env = environment(this_player());
   if (!who) ob = this_player()->query_current_attacker();
   else ob = present(who, env);
   if (!ob || !ob->is_living())
     return notify_fail("You do not see that here.\n");
   if (!this_player()->query_money(type))
     return notify_fail("You do not have a coin of that currency!\n");
   if (ob==this_player())
     return notify_fail("You toss a "+type+" coin into the air and catch
it.\n");
   if(this_player()->query_ghost())
    return notify_fail(
       "You cannot do that in your .. well... face it.. You're dead.\n");
   if (this_player()->query_disable())
     return notify_fail("You are not oriented enough to do this.\n");
   if (environment(this_player())->query_property("no attack"))
     return notify_fail("Greater powers prevent your malice.\n");
   if ((int)this_player()->query_sp() < 20)
    return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   this_player()->set_disable();
   this_player()->add_money(type, -1);
   dmg = random(this_player()->query_stats("strength")/10);
   dmg += random(this_player()->quey_level()/3);
   dmg += x;
   write("You flick a "+type+" coin at "
     ""+ob->query_cap_name()+"!"); 
   say(""+this_player()->query_cap_name()+" flicks a "
     +type+" coin at "+ob->query_cap_name()+"!",
     this_player());
   ob->damage(dmg);
   this_player()->add_sp(dmg/5);
   return 1;
}
void help() {
   write(@ENDTEXT
Syntax: <flick [currency] at [living]>
This is a jester attack that allows you to flick a coin at a
living target. You will actually lose one coin of the chosen
currency. The more the currency is worth the slightly more the
damage given will be.
ENDTEXT);
}
int abil() {
   object r;
   r = this_player();
   if (r->query_class() == "wanderer" && r->query_subclass() == "jester" &&
       r->query_level() >= 2) return 1;
}
