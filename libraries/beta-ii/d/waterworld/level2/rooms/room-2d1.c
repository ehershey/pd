/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("Several dozen tube worms are collected around a steam vent on the reef."
   " There are even a few 'pompeii worms' in the area around the thermal vent."
   " A large collection of green sulfur bacteria are just outside the vent."
  );

  set_exits(([
    "southeast":ROOMS2"room-2e2.c",
    "southwest":ROOMS2"room-2c2.c"
   ]));
  set_items(([
    "tube worms":"These unique animals can reach lengths of 8 feet."
    " Hair-like filaments act like 'gills' for the tube worm, oxidizing the chemicals from the vent for the creature."
    " The tube worms 'eat' by way of a symbiotic relationship with a microbe. The microbe uses chemosynthesis to convert energy for them both to use from the chemicals released by the vents.",
    "pompeii worms":"The Pompeii worms live in clusters around the opening to the thermal vents."
    " They breathe with a set of red-colored gills (tinted red by haemoglobin, a lower form of hemoglobin) located on their heads."
    " Unfortunately not much is known about them, all samples of the pompeii worms have died due to the decompression when they were brought to the surface.",
    "green sulfur bacteria":"These bacteria are one of the first known to use chemosynthesis."
    " Chemosynthesis uses sulfur from thermal vents to produce energy as opposed to photosynthesis which uses light and water."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
