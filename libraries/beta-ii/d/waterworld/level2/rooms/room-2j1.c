/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","The sounds of a humpback whale echo through here.");
  set_long("Most of this area of the reef seems deserted except for some crabs."
   " Some trash seems to have settled in this section and killed most of the lifeforms here."
   " A humpback whale is swimming past a few hundred yards away, bellowing to his kind.");

  set_exits(([
    "southeast":ROOMS2"room-2k2.c",
    "southwest":ROOMS2"room-2i2.c"
   ]));
  set_items(([
    "whale":"It is too far away to make out any details.",
    "trash":"A collection of discarded junk from Tirun which is polluting the coral reef.",
    "reef":"Most of the plant and animal life is dead or dying here."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
