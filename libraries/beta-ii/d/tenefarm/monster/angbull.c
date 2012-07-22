#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("bull");
  set_id( ({ "bull" }) );
  set("aggressive", 75);
  set_short("An angry bull");
  set_long("This bull seems to have escaped from somewhere. It looks very annoyed as it charges about.");
  set_gender("male");
  set_race("bull");
  set_body_type("equine");
  set_level(20);
  set_moving(1);
  set_speed(5);
}
