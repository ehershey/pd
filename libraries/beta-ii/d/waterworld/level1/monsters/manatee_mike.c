/// Monster file for Tirun Bay
/// By ironman
///
#include <std.h>
#include <waterworld.h>
#include <daemons.h>

inherit MONSTER;
object pearls;
string TARGET_ROOM;

object myself;

void create()
      {::create();
           myself=this_object();
           set_name("mike");
           set_id(({"manatee mike","manatee","mike"}));
           set_short("%^GREEN%^Manatee Mike%^RED%^, the warehouse manager.");
          set_long("%^GREEN%^Manatee Mike%^RESET%^ is a large manatee with a strong stout tail and massive flippers. There is something forboding about this manatee. He bears the '%^ORANGE%^Screaming Pelicans%^RESET%^' tattoo on his neck. He has a clipboard tucked under one of his flippers.");
           set_level(100);
           set_body_type("fish");
           set_race("manatee");
           set_gender("male");
           set_class("clergy");
           set_class("cleric");
    set_property("passive", 1);
           set_emotes(2,({
                "%^GREEN%^Manatee Mike%^RESET%^ scans over his clipboard to see what whales are getting cleaned today.",
                "%^GREEN%^Manatee Mike%^RESET%^ swims over to a filing cabinet and rustles through the papers inside.",
                "%^GREEN%^Manatee Mike%^RESET%^ inspects the quality control seals on the %^BOLD%^Whale Oil%^RESET%^ barrels.",
                "%^GREEN%^Manatee Mike%^RESET%^ looks you over trying to determine if you're a client of his or not."
                           }),0);

            new(WEP1"clipboard.c")->move(this_object());
             force_me("wield clipboard");
}
//// Quest routines

void catch_tell(string recieved) {
          string pname;
          string scraps;
          object pearls;

        recieved = TERMINAL_D->no_colours(recieved);

           if(sscanf(recieved,"%s asks: %*swhale oil%*sPelican Paul%*s",pname) >=3)
           {
               call_out("response_message",2,pname);
               return;
                 }
           else if(sscanf(TERMINAL_D->no_colours(recieved),"%s gives you A ROYAL blue pearl",pname,scraps)>=1)
               {
               call_out("barrel_loader",2,pname);
               return;
                     }
           else
                {
                   if(pearls=present("pearl")) { 
                         pearls->remove();
                         force_me("say I appreciate your gift "+pname+" but I require a %^BLUE%^%^BOLD%^ROYAL blue%^RESET%^ pearl for payment on the Whale oil.");
                         force_me("emote tosses the pearl into his vault and slams it shut!!");
                          }
           }
}

void response_message(string pname) {
          if(!present(pname))
              {
                force_me("tell "+pname+" I'm extremely busy right now partner!! You need to come to my office if you wish to talk to me.");
                force_me("emoteto "+pname+" growls at you for disturbing his work!!");
                 return;
                }
           else
                {
                 force_me("tell "+pname+" Sure, you can have a barrel of Whale Oil. All you need to do is locate a Blue Pearl and give it to me in payment for the barrel.");
                 force_me("smile "+pname);
                 return;
                 }
}

void barrel_loader(string pname)  {
         if(pearls=present("pearl")) {
               pearls->remove();
              force_me("say thank you for your payment "+pname+". Here is your %^BOLD%^barrel of Whale Oil%^RESET%^.");
              new(ITEMS1"whale_oil.c")->move(myself);
              force_me("give barrel to "+pname);
              return;
               }
         }

int is_invincible() {
      object TP=previous_object();
      string cap_TP=TP->query_name();

      message("info","%^GREEN%^Manatee Mike%^RESET%^ crashes into YOU!!\nYou are hurled through the open door of his office onto the docks!!\n\n",TP);
      message("info","%^GREEN%^Manatee Mike%^RESET%^ crashes into "+cap_TP+"!!\n"+cap_TP+" is hurled through the open door of the office onto the docks!!\n\n",environment(TP),TP);
      call_out("bouncer",1,TP);
      return 1;
}

void bouncer(object TP) {
       string cap_TP=TP->query_cap_name();
          TP->move(ROOMS1"secret-2c.c");
          message("info","You land flat on your back in the middle of the docks outside %^GREEN%^Manatee Mike%^RESET%^'s office!!",TP);
        message("info",cap_TP+" comes flying out of the office!!\n"+cap_TP+" lands flat on "+TP->query_possessive()+" back in the middle of the docks!!\n",(ROOMS1"secret-2c.c"),TP);
      (environment(TP))->remote_control(cap_TP);

}
