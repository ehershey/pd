//     /bin/user/_bite.c
//     A dragon physical attack
//     Nightshade
 
#include <std.h> 
inherit DAEMON;
int abil(); 

int cmd_bite (string str) {

   int attack, total;
   object ob;
   if(this_player()->query_race() == "vampire") return
      "/cmds/vamp/_bite.c"->cmd_bite(str);
   if (!abil())
      return 0;
   if(this_player()->query_ghost()) {
      notify_fail("You cannot do that as a ghost.\n");
      return 0;
   }
   ob = (object)this_player()->query_current_attacker();
   if(!ob || !living(ob)) {
      notify_fail("That is not here.\n");
      return 0;
   }
   if (this_player()->query_disable())
     {
      write("You are off balance.");
      return 1;
     }
 
   if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("You cannot do that here.\n");
      return 0;
   }
    if((int)this_player()->query_sp() < 30) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    if (((this_player()->query_skill("attack") / 5) -
               (ob->query_skill("defense") / 9 )) + 40 +
               ((this_player()->query_stats("strength")/4 -
                ob->query_stats("dexterity")/8)) < 1)
      {
       write("You miss your opponent.");
       tell_room(environment(this_player()), this_player()->query_cap_name()+" tries to bite "+ob->query_cap_name()+"!", ({ ob, this_player() }));
       return 1;
      }
      write("You %^BOLD%^%^RED%^BITE%^RESET%^ "+ob->query_cap_name()+"!\n");
      attack = ((this_player()->query_skill("attack") / 4) -
               (ob->query_skill("defense") / 7 )) + 50 +
               ((this_player()->query_stats("strength")/3 -
                ob->query_stats("dexterity")/8));
      tell_room(environment(this_player()), this_player()->query_cap_name()+ "%^BOLD%^%^RED%^ BITES%^RESET%^ "+(string)ob->query_cap_name() + ".\n", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" %^BOLD%^%^RED%^BITES%^RESET%^ you hard!\n");
      total = (attack/5 + random(this_player()->query_level()));
      this_player()->add_skill_points("attack", total/30);
      this_player()->add_sp(-total/7);
      ob->damage(total+(random(this_player()->query_level()/2)));
      return 1;
   }

void help() {
   if(this_player()->query_race() == "vampire") {
     write("Syntax: <bite>\n\n"
          "This will allow you to bite your victim and drain the life "
          "of your victim and replunish your bp.");
    return;
    }
   write("Syntax: <bite>\n\n"
         "When a dragon is in battle, they may bite their opponent, \n"
         "inflicting much damage.  This is a simple attack for all dragons. ");
}

int abil() {
   if (this_player()->query_class() != "dragon") return 0;
   return 1;
}
