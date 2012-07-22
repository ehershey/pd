/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
     set_listen("default","You hear the sound of the buoy's bell.");
         set_long("There is a rather large saltwater buoy tethered here to the bay's floor."
              " There are numerous pelicans and seagulls sitting on the water here."
              " Most of the fish avoid the area out of fear of being eaten.");

         set_exits(([
               "east":ROOMS1"room-1e5.c",
               "south":ROOMS1"room-1d6.c",
               "west":ROOMS1"room-1c5.c",
               "north":ROOMS1"room-1d4.c"
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
