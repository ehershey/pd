/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A school of tilapias have apparently made a home for themselves in a bed of seagrass."
   " They are eating the seagrass as well as the shellfish from the reef."
   " The sponges and corals seem to be to toxic for the tilapias."
   " As a result, the animals that reside in and around the sponges and corals are safe from the tilapias' feedings."
  );

  set_exits(([
    "northeast":ROOMS2"room-2d3.c",
    "southeast":ROOMS2"room-2d5.c",
    "southwest":ROOMS2"room-2b5.c",
    "northwest":ROOMS2"room-2b3.c"
   ]));
  set_items(([
    "tilapias":"These fish, members of the cichid family, resemble a bass or perch."
    " The differences between tilapias and basses and perches are in the dorsal fins."
    " Tilapias have one long dorsal fin while perches and basses have a set of two dorsal fins."
    " They have a wide variety of colors and markings."
    "\n\nTilapias are more commonly known as 'whitefish'.",
    "seagrass":"The main food supply, along with shellfish, for the tilapias."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
