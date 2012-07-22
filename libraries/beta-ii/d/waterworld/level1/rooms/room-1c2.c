/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));

        set_long(
                "A large tidal pool dominates this whole area."
                 " Most creatures would be well over their heads here."
                 " The currents are quite strong and tend to sweep weak swimmers out to sea."
                  " It appears the current flows from a rip-tide to the north." 
                 );
         set_exits(([
           "east":ROOMS1"room-1d2.c",
           "south":ROOMS1"room-1c3.c",
           "west":ROOMS1"room-1b2.c",
           "north":ROOMS1"room-1c1.c"
                     ]));
         set_items(([
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
