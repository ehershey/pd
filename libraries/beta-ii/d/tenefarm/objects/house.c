#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_name("house");
  set_short("The farmer's house");
  set_long("This is the farmer's house, where he lives with his wife. It looks rather new, and appears to be freshly painted.");
  set_prevent_get("You try to pick up the house and feel stupid.");
  set_mass(560);
  set_id(({ "house" }));
}
