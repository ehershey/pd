#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("man");
  set_id(({ "young man", "man" }));
  set_short("A young man");
  set_long("This young man seems to have found a perfect spot to hide out with his girlfriend, but he appears to be having a hard time finding her in the hay.");
  set_gender("male");
  set_race("human");
  set_body_type("human");
  set_level(16);
}
