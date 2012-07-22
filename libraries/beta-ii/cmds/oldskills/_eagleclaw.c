// a dungeonware.net production
// based on Coupe De Grace by Nightshade
#include <daemons.h>
inherit DAEMON;
int abil();
string gen;
int cmd_eagleclaw(string str)
{
  int dmg;
  object ob;
   if (!abil()) {
      return 0;
   }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(this_player()->query_rest_type()) {
        notify_fail("You do anything while sitting.");
        return 0;
   }
     ob = this_player()->query_current_attacker();
   if (!ob)
       {
        write("You are not in combat.");
        return 1;
       }
     if (ob==this_player())
      {
       write("Something must be wrong with you.");
       return 1;
      }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(!living(ob)) {
      write("Now is not the time for target practice.");
      return 1;
    }
    
 if (this_player()->query_sp() < 50) 
   {
    write("You are too tired to preform such a task.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
   this_player()->set_disable();
   dmg = this_player()->query_skill("attack") -
        ob->query_skill("defense") +
        this_player()->query_stats("strength")*4 +
        this_player()->query_stats("dexterity")*3 -
        ob->query_stats("dexterity")/2 -
        ob->query_stats("constitution")/2;
   if (this_player()->query_gender()=="male") gen = "he"; else gen = "she";
   if((ob->is_player() ? dmg*3/4 : dmg) < ob->query_hp()) {
       write("You try to crush "+ob->query_cap_name()+"'s throat, but fail!\nYou are thrown terribly off balance from your misjudgement!");
       say(this_player()->query_cap_name()+" tries to crush "+ob->query_cap_name()+"'s throat and fails, making "+objective(this_player())+" loose "+possessive(this_player())+" balance.", ob);
       message("info",this_player()->query_cap_name()+" tries to crush your throat, but falls off balance!", ob);
       ob->damage(dmg/10);
       this_player()->set_paralyzed(2+random(2), "You have yet to regain your balance after your attempt to Eagle Claw "+ob->query_cap_name()+"!");
   }
   else {
       write("%^BOLD%^%^RED%^With grim satisfaction you crush "+ob->query_cap_name()+"'s throat.%^RESET%^");
       say("%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" grimaces as "+gen+" crushes "+ob->query_cap_name()+"'s throat.%^RESET%^", ob);
       message("info", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" grimaces as "+gen+" crushes the life out of you.%^RESET%^", ob);
       ob->damage(dmg*2);
   }
     this_player()->add_sp(-dmg/6);
   return 1;
}
int abil() {
   if(this_player()->query_level() < 40) return 0;
   if (this_player()->query_subclass() == "monk") return 1;
   return 0;
}
void help() {
   write("Syntax: <eagleclaw>\n\n"
      "A powerful monk can use this ability to crush the throat of an enemy who is close to death, though, using Eagleclaw to early in battle will put the monk off balance.\n"); }