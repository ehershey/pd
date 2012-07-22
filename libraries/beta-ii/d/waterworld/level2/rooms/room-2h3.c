/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("There seems to be an overabundance of sea grass on the reef here."
   " The sea grass comes in a wide variety of colors and forms."
   " A colony of pelagic fish have chosen the sea grass as their nesting grounds."
   " Unfortunately for the sea grass, most of the fish and turtles find them to be quite tasty treats."
  );

  set_exits(([
    "northeast":ROOMS2"room-2i2.c",
    "southeast":ROOMS2"room-2i4.c",
    "southwest":ROOMS2"room-2g4.c"
   ]));
  set_items(([
    "sea grass":"The sea grass is a main staple of food for most of the creatures that live in the reef ecosystem.",
    "pelagic fish":"A general classification for fish including herring, mackerel and cods."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
