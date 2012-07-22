/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_listen("default","You hear the gentle sound of waves washing over the sand.");
      set_smell("default","There seems to be a strong scent of fish here.");
      set_long(
          " Many species of fish have selected this area for their nesting grounds."
           " Clusters of fish eggs line the soft sand several feet below the water's surface."
           " Over-protective parents are protecting their nests from predators."

               );
         set_exits(([
               "east":ROOMS1"room-1b7.c",
               "north":ROOMS1"room-1a6.c",
               "northeast":ROOMS1"room-1b6.c"
                     ]));
         set_items(([
                "fish eggs":"Mama fish is resting near the eggs."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
