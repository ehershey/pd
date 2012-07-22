#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("girl");
   set_id( ({ "girl", "vampire" }) );
   set_short("A very sad girl");
   set("aggressive", 1);
   set_level(50);
   set_long("This girl looks extremely sad.  She is very beautiful and dressed up for the ball.");
   set_body_type("human");
   set_race("vampire");
   set_gender("female");
  
}

void catch_tell(string str) {
    string a, b;
    if(sscanf(str, "%shats wrong%s", a, b) == 2)  
         force_me("say Oh, I can't go to the ball...  I waited all year for this but now I'm grounded...  this invitation is worthless to me!");
}

void catch_tell(string str) {
    string a, b;
    if(sscanf(str, "%snvitation%s", a, b) == 2)  
         force_me("say You want my invitation?  I suppose I could sell it to you and make my money back...  Would you really like to buy it?");
}
 
void heart_beat(){
 ::heart_beat();
  if(random(100)<5)force_me("cry");
}


