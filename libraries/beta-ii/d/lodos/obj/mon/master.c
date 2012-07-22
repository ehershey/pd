#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("master of the hunt");
   set_id(({ "master", "hunter", "huntmaster", "hunt master", "raknid" }));
   set_name("master");
   set_level(28);
   set_long("At first the hunter looks like a raknid, but then "
     "you notice two extra arms and leathery bat-like wings. The "
     "huntmasters wander about, sometimes in groups, and other times "
     "in solitary hunting down anything they can find in the forest. "
     "The hunters are known for their cruel love of slaughtering "
     "those people who leave the comfort of their towns and venture into "
     "the forest. Noone but the sages know whether there is some "
     "civilization of this foul race, or if the masters of the hunt are "
     "the only of their kind.");
   set_body_type("sacron");
   set_race("sacron");
   set("aggressive", 13); 
   set_gender("male");
   set_heart_beat(1);
   set_alignment(-800);
   make(WEA"haxe");
   make(WEA"bwhip");
   make(WEA"bwhip");
   make(WEA"cblade");
   make(WEA"kris");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wield axe");
     force_me("wield whip");
     force_me("wield whip 2");
     force_me("wield blade");
     force_me("wield kris");
     if (present("snake", environment(this_object())))
       force_me("ride snake");
     oi = 1;
   }
}
