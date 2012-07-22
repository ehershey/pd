#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
     ::create();
     set_name("calf");
     set_id(({ "cow", "calf" }));
     set_short("A young calf");
     set_long("A very young calf. This calf rests on the path next to the river, taking a drink every few minutes.");

     if (random(2) < 2)
     set_gender("female");
     else
     set_gender("male");
     set_race("cow");
     set_body_type("equine");
     set_level(16);
}
