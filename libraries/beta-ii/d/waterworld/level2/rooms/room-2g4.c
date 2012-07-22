/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "Several of the fish in this area appear to be host to some lampreys."
   " There are a few that have even died from having their fluids drained away by these parasitic fish."
   " The scavengers seem to be making a buffet out of the dead fish bodies lining the reef."
  );

  set_exits(([
    "northeast":ROOMS2"room-2h3.c",
    "southeast":ROOMS2"room-2h5.c",
    "northwest":ROOMS2"room-2f3.c",
    "southwest":ROOMS2"room-2f5.c"
   ]));
  set_items(([
    "fish":"Almost all types of fish and animals fall prey to the lampreys.",
    "lamprey":"They have an eel-like body at first glance."
    " The dorsal and caudal fins differentiate them from eels and place them distinctly in the fish family."
    " Unlike most fish, the lamprey feeds by attaching itself to a host and draining its fluids for nourishment (primarily the blood).",
    "bodies":"Most lampreys will quite literally suck the life out of their host before letting go of them."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
