#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_short("hay");
  set_long("Large quantities of hay are stored in the hayloft. This hay looks extremely fresh.");
  set_prevent_get("There is far too much hay to pick up.");
  set_mass(160);
  set_name("hay");
  set_id(({ "hay" }));
}
