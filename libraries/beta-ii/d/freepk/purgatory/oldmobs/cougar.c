#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("cougar");
   set_short("cougar");
   set_id(({"monster", "cougar"}));
   set_long("A nasty looking cougar.");
   set_level(38+random(5));
   set("aggressive", 200);
   set_gender("male");
   set_race("cougar");
   set_body_type("raknid");
   set_swarm("");
   set_skill("melee", 250);
   set_emotes(2,({ "A cougar rustles the grasses near you." }),0);

}