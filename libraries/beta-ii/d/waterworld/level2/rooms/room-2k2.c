/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","The song of the humpback whale is deafening in this area.");
  set_long("A collection of shrimp have assembled in this area and are eating the bacteria in the water."
   " Unfortunately for the shrimp, they are in turn being eaten by the whale that has been entertaining the reef with his beautiful song."
   " The pollution sees to have infested this section of the reef as well.");

  set_exits(([
    "northwest":ROOMS2"room-2j1.c",
    "southwest":ROOMS2"room-2j3.c",
    "southeast":ROOMS2"room-2l3.c"
   ]));
  set_items(([
    "shrimp":"The main food supply of shrimp is bacteria. These guys are right at home with all the pollution here.",
    "whale":"The main food supply of some whales (such as the humpback whale) is bacteria, algae and small animals like the shrimp here."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
