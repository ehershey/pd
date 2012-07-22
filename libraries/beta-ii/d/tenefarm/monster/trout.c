#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("fish");
  set_id( ({ "fish", "trout" }) );
  set_short("A trout (swimming)");
 set_long("A large trout. This fish is very big, but it doesn't look very edible.");
  set_gender("neuter");
  set_race("fish");
  set_body_type("fish");
  set_level(14+random(6));
}
