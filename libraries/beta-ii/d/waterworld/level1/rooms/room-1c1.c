/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_smell("default","You smell Bar-B-Q shrimp!!!");
       set_long("There is an old sea captain here cooking some shrimp on a bar-b-q."
                " He seems to have a nice collection of them already on the plate next to his chair."
                " The beach extends far to the east and west from here."
                " Tirun bay is directly to the south.");

         set_exits(([
        "north":"/d/nopk/tirun/beach/3,1,0",
                 "east":ROOMS1"room-1d1.c",
                 "south":ROOMS1"room-1c2.c",
                 "west":ROOMS1"room-1b1.c"
                     ]));
         set_items(([
               "captain":"He seems like a very friendly fellow.",
                "shrimp":"They're absolutely mouth-watering."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
          
MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
