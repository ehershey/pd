#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Tiaquat");
   set_short("Tiaquat");
   set_id(({"monster", "tiaquat"}));
   set_long("A strange looking quadruped, no telling what forces were at work at its creation.");
   set_level(5+random(15));
   set("aggressive", 5+random(30));
   set_invis();
   set_swarm("");
   set_gender("female");
   set_race("tiaquat");
   set_heart_beat(1);
   set_body_type("hornedequine");

}
