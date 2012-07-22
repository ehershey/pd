/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_long(
          "The open waters of Tirun bay extend in every direction."
           " A few jellyfish and some plankton are floating past."
           " Countless baitfish are feeding on the plankton."
           " Gentle waves rustle past making everything rock in a rhythmic manner."
              );

         set_exits(([
              "east":ROOMS1"room-1c5.c",
               "south":ROOMS1"room-1b6.c",
              "west":ROOMS1"room-1a5.c",
              "north":ROOMS1"room-1b4.c"
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
