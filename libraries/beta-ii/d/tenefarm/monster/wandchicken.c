#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
     ::create();
     set_name("chicken");
     set_id(({ "chicken", "monster" }));
     set_short("A wandering chicken");
     set_long("This chicken must have gotten away from somewhere, because it wanders around aimlessly.");
     set_gender("male");
     set_race("fowl");
     set_body_type("fowl");
     set_level(16);
     set_speed(6);
}
