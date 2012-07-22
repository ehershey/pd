/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_long(
            "Water is the only thing that can be seen here other than a family of feeding pelicans."
            " The parents are taking turns diving for fish then bringing it up to their young to eat."
            " The baby pelicans appear very content just to bob in the waves and wait for dinner."
           );

         set_exits(([
                 "east":ROOMS1"room-1g4.c",
                 "south":ROOMS1"room-1f5.c",
                  "west":ROOMS1"room-1e4.c",
                  "north":ROOMS1"room-1f3.c"
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
