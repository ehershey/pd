#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
set_name("gracken");
set_short("Gracken, the Ancient Sage");
set_long("Gracken has seen his fair share of battles and has always come out on top.  He is long since retired from the world of adventure and has settled here selling magical goods to Merkkirri.");
set_race("gnoll");
 set_gender("male");
set_id(({"gracken", "owner", "sage"}));
}

void init()
{
 ::init();
 add_action("fBuy", "buy");
 add_action("fRead", "read");
 set_heart_beat(10);
}
int fRead(string str)
{
 if (!str || str!="sign")
   return notify_fail("Read what?\n");
 say (this_player()->query_cap_name()+" reads over the sign.");
 write("The sign reads:
-----------------------------------------
 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 30 gold peices )
-----------------------------------------");
 return 1;
}
int fBuy(string str)
{
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="stone" && str!="magical stone")
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "stone": case "magical stone":
   if (this_player()->query_money("gold") < 30)
     { this_object()->force_me("say You do not have 30 gold for the stone.");
       return 1; }
this_player()->add_money("gold", -30);
   write("Gracken hands you a magical stone.");
   say ("Gracken hands "+this_player()->query_cap_name()+" a magical
stone.");
   new("/std/obj/stone")->move(this_player());
   return 1;
   break;
 }
}

 void heart_beat()
{
 if (random(50) > 25)
 this_object()->force_me("say I buy un-used stones found in the ocean.");

}
