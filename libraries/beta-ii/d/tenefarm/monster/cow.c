#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("cow");
  set_id( ({ "cow", "farm_cow" }) );
  set_short("A spotted cow");
  set_long("A spotted black and white cow");
  set_gender("female");
  set_race("cow");
  set_body_type("equine");
  set_level(12);
  set_moving(1);
  set_speed(12);
}
