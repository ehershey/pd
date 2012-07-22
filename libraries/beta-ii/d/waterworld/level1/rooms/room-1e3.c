/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_long("This tidal pool is one of several in the Tirun bay."
                " Turtles seem to have taken to making their nests in the sandy bottom."
                " The water flows very gently in this area.");

         set_exits(([
            "north":ROOMS1"room-1e2.c",
            "northeast":ROOMS1"room-1f2.c",
            "east":ROOMS1"room-1f3.c",
            "south":ROOMS1"room-1e4.c",
            "southwest":ROOMS1"room-1d4.c",
            "west":ROOMS1"room-1d3.c"
                     ]));
         set_items(([
               "turtles":"Most of the turtles are guarding their nests from predators.",
               "nests":"Multiple eggs line almost all the nests in the tidal pool."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
