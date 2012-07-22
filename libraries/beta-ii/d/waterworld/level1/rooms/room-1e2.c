/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_long("The pelicans appear to have made a comfortable nesting ground for themselves on a little island here."
                " There are pelicans literally covering this island here."
               " The water is filled with fish."
               " The over abundance of food is most likely what has attracted so many pelicans."
          );

         set_exits(([
             "east":ROOMS1"room-1f2.c",
             "south":ROOMS1"room-1e3.c",
             "west":ROOMS1"room-1d2.c",
             "north":ROOMS1"room-1e1.c"
                     ]));
         set_items(([
          "pelicans":"There are a LOT of pelicans on this tiny island. Most of them with nests and babies.",
            "island":"This tiny island is about 50 yards around the perimeter.",
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
