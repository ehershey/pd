/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear the waves breaking against the sand");
        set_long("This section of the beach has been washed out.  The water is only hip deep for the average human."
                 " Beware of the strong rip-tide.");

        set_exits(([
            "east":ROOMS1"room-1b4.c",
            "south":ROOMS1"room-1a5.c",
            "north":ROOMS1"room-1a3.c"
             ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
