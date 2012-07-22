/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_listen("default","Strange. There is a soft sound of machinery but no apparent source.");
      set_smell("default","You smell smoke in the air.");
       set_long("This section of the seashore is peaceful. There is a small shop to the east of here. Multiple clumps of seaweed float along the surface of the water.");

         set_exits(([
                 "east":ROOMS1"room-1g7.c",
                  "north":ROOMS1"room-1f6.c",
                  "west":ROOMS1"room-1e7.c"
                     ]));
         set_items(([
                  "shop":"There is a sign on the top of the shack.",
                   "sign":"The sign reads 'Pete's Pearl Palace and Sea Shanty' ",
                   "seaweed":"Ordinary seaweed.  Nothing new to see here."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
