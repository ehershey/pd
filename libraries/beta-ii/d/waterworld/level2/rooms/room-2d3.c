/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A family of dugong have made their home in a small cavern under the reef."
   " The dugong are feeding upon the massive collection of sea grass lining the ocean floor outside their cavern."
   " A dugong corpse lays on the ocean floor. It would appear it got attacked by a shark and this is all that remains."
  );

  set_exits(([
    "northeast":ROOMS2"room-2e2.c",
    "southeast":ROOMS2"room-2e4.c",
    "southwest":ROOMS2"room-2c4.c",
    "northwest":ROOMS2"room-2c2.c"
   ]));
  set_items(([
    "dugong":"Dugong are a relative of manatees."
    " A typical adult measures a maximum of 9 feet and weighs no more than 300 pounds."
    " The dugong have a slow breeding rate and long life span."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
