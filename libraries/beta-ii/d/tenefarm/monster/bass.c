#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("fish");
  set_id( ({ "fish", "bass" }) );
  set_short("A bass (swimming)");
  set_long("This bass is very fat. It swims around in small circles, bumping its head into things that get in its way.");
  set_gender("female");
  set_race("fish");
  set_body_type("fish");
  set_level(12+random(2));
}
