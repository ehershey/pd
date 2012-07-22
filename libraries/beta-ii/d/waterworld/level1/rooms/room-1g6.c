/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear a foghorn in the distance.");
       set_long("There is a large stone jette to the east of you.  The waves crash violently against the jagged rocks.  Multiple sea creatures seem to have made the gaps between the rocks into homes, especially crabs.");

         set_exits(([
               "north":ROOMS1"room-1g5.c",
                "south":ROOMS1"room-1g7.c",
                "west":ROOMS1"room-1f6.c"
                     ]));
         set_items(([
                   "jette":"This is a MASSIVE stone jette constructed of several boulders.",
                   "boulders":"They're rocks..... what ya expect??",
                    "crabs":"Crabs of every shape and size are crawling around the rocks."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
