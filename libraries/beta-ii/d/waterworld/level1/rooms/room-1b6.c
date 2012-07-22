/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_long("A deep tidal pool dominates this section of the bay. It is very hard for the average adventurer to find footing. There is a strong undertow here pulling at the feet of anyone entering its path. Be careful not to be swept out to sea.");

         set_exits(([
               "north":ROOMS1"room-1b5.c",
                "northeast":ROOMS1"room-1c5.c",
                "east":ROOMS1"room-1c6.c",
                "south":ROOMS1"room-1b7.c",
                 "southwest":ROOMS1"room-1a7.c",
                "west":ROOMS1"room-1a6.c"
                     ]));
         set_items(([
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
