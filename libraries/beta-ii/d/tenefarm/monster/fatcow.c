#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("cow");
  set_id(({ "cow", "fatcow", "fat cow" }));
  set_short("A very fat cow");
  set_long("A spotted black and white cow. This cow has gorged itself on grass, and is too fat to be able to move around very much.");
  set_gender("female");
  set_race("cow");
  set_body_type("equine");
  set_level(17);
}
