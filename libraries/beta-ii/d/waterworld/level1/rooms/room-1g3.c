/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
         set_listen("default","You hear running water nearby");
        set_smell("default","It smells like a compost heap here.....");
        set_long("This section of the jette seems to have some plants growing on it."
                " Several of the plants are also floating on the water."
                " A large refuse slick covers the area."
                " Garbage, as well as other 'items', have washed up on the jette."
                  );

         set_exits(([
"east":"/d/nopk/tirun/beach/7,4,0",
                   "north":ROOMS1"room-1g2.c",
                   "south":ROOMS1"room-1g4.c",
                   "west":ROOMS1"room-1f3.c"
                     ]));
         set_items(([
                   "plants":"They seem to be some form of salt-water lily.",
                   "refuse":"The garbage seems to be flowing into the area from the south."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
