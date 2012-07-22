/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear the waves breaking against the sand");

        set_long(
              "A hundred feet or so of sand has been washed away."
               " There is a very strong rip-tide pulling along the bottom of the water in this area."
               " Fortunately, the sand dunes to the north have held when the beach eroded."
               " Any traveller trying to cross this area needs to be careful not to be washed out to sea by the rip-tide."
             );
         set_exits(([
        "north":"/d/nopk/tirun/beach/2,1,0",
              "east":ROOMS1"room-1c1.c",
              "south":ROOMS1"room-1b2.c",
              "west":ROOMS1"room-1a1.c",
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
