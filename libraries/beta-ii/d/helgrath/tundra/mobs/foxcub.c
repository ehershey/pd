#include <std.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Fox cub");
   set_short("Fox cub");
   set_id(({"monster", "fox", "cub", "fox cub"}));
   set_long("Just a normal playful fox cub looking for a playmate.");
   set_level(18+random(6));
   set("aggressive", 10+random(5));
   if(random(2)) set_gender("male"); else set_gender("female");
   set_race("fox cub");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("canine");
   set_emotes(2,({ "The cub leaps about, playing with a mouse.", "A small pressure can be felt against your leg as the cub bumps into you." }),0);
}

