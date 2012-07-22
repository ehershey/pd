/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_long(
            " This area is the open water of Tirun bay."
            " The water is severely rough in this area."
            " Waves towering over 8 feet high roll past swamping anything in their path."
             " Even the birds are smart enough to avoid the bay when it gets this rough."
                );

         set_exits(([
              "east":ROOMS1"room-1d3.c",
              "southeast":ROOMS1"room-1d4.c",
              "south":ROOMS1"room-1c4.c",
              "west":ROOMS1"room-1b3.c",
              "northwest":ROOMS1"room-1b2.c",
              "north":ROOMS1"room-1c2.c"
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
