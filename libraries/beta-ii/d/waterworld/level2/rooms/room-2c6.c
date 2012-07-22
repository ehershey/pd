/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "The wreckage of a small boat is resting on a ledge overhanging the reef."
   " A school of red snappers have made quite a home for themselves in and around the wreck."
   " The snappers seem to be feasting on the crustaceans and small fish in this area."
  );
  add_invis_exit("cabin");
  set_exits(([
    "cabin":ROOMS2"secret-6a.c",
    "northeast":ROOMS2"room-2d5.c",
    "southeast":ROOMS2"room-2d7.c",
    "northwest":ROOMS2"room-2b5.c"
   ]));
  set_items(([
    "wreckage":"It's the remains of a small clipper ship. "
    "Some parts, like the cabin, seem to be intact.",
    "red snapper":"The red snapper is a very typical citizen of a reef ecosystem."
    " They weigh an average of 10 pounds and measure 20 inches as adults."
    " They have pink to red pigments on their back and dorsal sections of their bodies."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
