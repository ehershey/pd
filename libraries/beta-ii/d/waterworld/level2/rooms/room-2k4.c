/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("A school of cardinal fish are swimming past this area."
   " Several pieces of 'Christmas tree coral' inhabit this section of the reef."
   " A multitude of smaller fish schools are in the area including a few flounders.");

  set_exits(([
    "northwest":ROOMS2"room-2j3.c",
    "northeast":ROOMS2"room-2l3.c",
    "southeast":ROOMS2"room-2l5.c",
    "southwest":ROOMS2"room-2j5.c"
   ]));
  set_items(([
    "cardinal fish":"These scarlet colored fish swim in packs called 'schools' to fool predators into thinking they are actually a large fish.",
    "christmas tree coral":"This is a sample of black coral that is about 3 feet in height and resembles a douglas fur in appearance.",
    "flounder":"This type of fish has evolved with both eyes on the upper side of its body. This allows them to swim flatly against the ocean floor so predators have a harder time detecting and eating them."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
