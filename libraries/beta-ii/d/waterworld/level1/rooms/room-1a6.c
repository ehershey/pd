/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_listen("default","You hear several fish splashing in the waves");
        set_long(
             "Several schools of fish are cluttering the area."
              " It is extremely hard to see much through the fish other than water."
             " To make matters worse, a flock of pelicans have begun divebombing the schools for dinner."
                );

         set_exits(([
                  "east":ROOMS1"room-1b6",
                   "south":ROOMS1"room-1a7",
                  "north":ROOMS1"room-1a5"
                     ]));
         set_items(([
                    "fish":"This is a school of bait fish.",
                    "water":"Um.... It's only water. Can we move on now??"
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
