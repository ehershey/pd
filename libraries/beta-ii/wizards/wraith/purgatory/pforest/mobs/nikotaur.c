#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Nikotaur");
   set_short("Nikotaur");
   set_id(({"monster", "nikotaur"}));
   set_long("An ancient being that roams the forest in search of the perfect meal.");
   set_level(5+random(17));
   set("aggressive", 5+random(59));
   set_gender("female");
   set_race("nikotaur");
   set_heart_beat(1);
   set_body_type("dinosaur");


}
