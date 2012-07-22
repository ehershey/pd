/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A couple of salmon have decided to stop at the reef here to dine."
   " The salmon are focusing upon the bentic (or bottom dwelling) amphipods and crustaceans."
   " A pair of pelicans are diving from the surface to scoop up the salmon for lunch for themselves."
   " It looks like a couple of yellow salmon are resting in the seagrass to allow their bodies to osmoregulate to the saltwater after their swim downstream and into the bay."
  );

  set_exits(([
    "northeast":ROOMS2"room-2e6.c",
    "northwest":ROOMS2"room-2c6.c"
   ]));
  set_items(([
    "yellow salmon":"Once a salmon reaches the saltwater at the end of its birth river, it must take time for its body to adjust to the chemistry of the saltwater environment."
    " It is this process of osmoregulation that allows the fish to be anadromous, changing from freshwater to saltwater."
    " This change in the fish's basic chemistry is the fundimental reason why the salmon die when they return to freshwater to spawn."
    " Their bodies literally take in too much water due to osmotic pressure.",
    "salmon":"They are silver fish with red stripes along both sides."
    " Most adult salmon weigh in around 50 pounds but some have grown as large as 150 pounds and 58 inches long.",
    "amphipod":"This is the common term for shrimps and mollusks."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
