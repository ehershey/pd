/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_listen("default","You hear the sound of pelicans diving after fish.");
        set_long("The water runs very deep in this section of the bay. Multiple pilings litter the water here making it hard for anyone to swim in this area. Several pelicans have taken to the pilings to rest and eat their catch. Some pelicans are still diving for food.");

         set_exits(([
                 "east":ROOMS1"room-1e2.c",
                 "north":ROOMS1"room-1d1.c",
                 "south":ROOMS1"room-1d3.c",
                 "west":ROOMS1"room-1c2.c"
                  ]));
         set_items(([
              "pilings":"They seem to be part of an old dock that has been destroyed somehow.",
              "pelicans":"Large birds with sacs under the bills filled with todays catch of fish."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
