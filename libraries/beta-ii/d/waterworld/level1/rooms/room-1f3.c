/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear the bell of a buoy.");
        set_long("There is a large red and white buoy bobbing in the water here. Several seagulls have assembled on top of it."
             " There is a large jette jutting out into the sea to the east of here.");

         set_exits(([
                  "east":ROOMS1"room-1g3.c",
                  "south":ROOMS1"room-1f4.c",
                  "west":ROOMS1"room-1e3.c",
                  "north":ROOMS1"room-1f2.c"
                     ]));
         set_items(([
                    "buoy":"It's a standard issue buoy.",
                    "seagulls":"Seems most of them are dozing off. Must be resting after gorging on all the shrimp around here."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
