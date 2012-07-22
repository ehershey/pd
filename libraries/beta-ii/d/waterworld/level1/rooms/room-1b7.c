/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_listen("default","You hear the waves crashing against the many rocks lining the shoreline here.");
      set_smell("default","The smell of rotting seaweed hangs heavily in the air.");
       set_long("There are several rocks jutting out of the sand here.  A lot of seaweed seems to have washed over them in the last tide. Seems the current is a tad rough here. Some of the seaweed is being carried back out to sea.");

         set_exits(([
               "east":ROOMS1"room-1c7.c",
                "west":ROOMS1"room-1a7.c",
                "north":ROOMS1"room-1b6.c"
                     ]));
         set_items(([
                   "rocks":"Rocks of every size and shape are scattered through this area.",
                   "seaweed":"A large pile of seaweed is draped over the rocks here from the last tide. Most of it is dead and rotting from the smell of things.",
                  "sand":"A clam is sticking out of the sand."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
