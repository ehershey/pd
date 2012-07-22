/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_long("This is the edge of the beach."" The waves are rolling rhythmicaly up the shore and off the jette to the east."
                 " A large collection of broken shells litter the sand and jette."
               " Several hermit crabs are walking slowly along the sand.");

         set_exits(([
                   "north":ROOMS1"room-1g1.c",
                   "south":ROOMS1"room-1g3.c",
        "east":"/d/nopk/tirun/beach/7,3,0",
                   "west":ROOMS1"room-1f2.c"
                     ]));
         set_items(([
                    "waves":"The waves have a soothing effect on anyone who gazes upon them.",
                    "hermit crabs":"They're scavenging the shoreline for food.",
                     "sand":"It has the hermit crab's tracks all over it."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
