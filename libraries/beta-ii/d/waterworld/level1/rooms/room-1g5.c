/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_listen("default","You hear the squawking of numerous seagulls.");
        set_smell("default","You smell wet feathers. Lots of wet feathers.");
        set_long("The jette in this area is covered in seagulls of every shape and size."
              " Several of the nests seem to have eggs in them."
               " The water is littered with the remains of fish and crawfish.");

         set_exits(([
"east":"/d/nopk/tirun/beach/7,6,0",
                  "north":ROOMS1"room-1g4.c",
                  "south":ROOMS1"room-1g6.c",
                   "west":ROOMS1"room-1f5.c"
                     ]));
         set_items(([
                  "seagulls":"There are seagulls literally covering every inch of the jette here.",
                   "nests":"Many of the nests have baby seagulls in them. Others have eggs.",
               "remains":"The half eaten remains of fish and other animals."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
