/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("There is a large collection of tube worms that dominate this section of the reef."
   " A family of seahorses have seem to have made a nice home for themselves among the tube worms."
   " Most of the fish seem to avoid this area. It must be due to these tube worms."
   " The barrier reef continues for as far as the eye can see.");

  set_exits(([
    "northeast":ROOMS2"room-2j1.c",
    "southeast":ROOMS2"room-2j3.c",
    "southwest":ROOMS2"room-2h3.c",
    "west":ROOMS2"room-2h2.c"
   ]));
  set_items(([
    "tube worms":"They look like long stone pillars with tongues that shoot out after their prey.",
    "seahorses":"These critters seem to be immune to the tube worms' toxins."
   ]));
  new(PEARLS"purple_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
