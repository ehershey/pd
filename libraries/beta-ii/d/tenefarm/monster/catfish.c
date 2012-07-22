#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("fish");
  set_id(({ "fish", "catfish" }));
  set_short("A catfish (swimming)");
 set_long("This catfish seems to be resting in the water for a little bit after a long swim. It has very long whiskers.");
  set_gender("male");
  set_race("fish");
  set_body_type("fish");
  set_level(16+random(4));
}
