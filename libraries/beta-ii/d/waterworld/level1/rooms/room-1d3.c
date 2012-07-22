/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_listen("default","You hear the old wreckage creaking with the movement of the waves");
      set_smell("default","It smells like mildew.");
         set_long("There is a moderate size ship sunken here in the bay."
                 " Judging from the mildew and barnacles, the ship has been here for ages."
                  " It also looks like the crabs and crawfish have made a nice home for themselves in its rotted out hull.");

         set_exits(([
             "east":ROOMS1"room-1e3.c",
             "south":ROOMS1"room-1d4.c",
             "west":ROOMS1"room-1c3.c",
             "north":ROOMS1"room-1d2.c"
                     ]));
         set_items(([
                "barnacles":"Yes. They are in fact barnacles. Small water plants that feed on rotting lumber.",
                 "crabs":"It looks like you located the crab nesting ground.",
                 "ship":"Seems there's something lying inside the hull.",
                 "hull":"There is an old skeleton lying inside the ship."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
