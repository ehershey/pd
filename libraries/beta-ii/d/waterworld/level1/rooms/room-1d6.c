/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_listen("default","You hear the labored breathing of a whale straining to breath in the shallow tidal pool");
        set_smell("default","The fishy smell of the whale's breath fills the air.");
        set_long("The head and upper body of a whale lie here. The tail of this once mightly beast is extended to the west. The waves are breaking against the whale's side, spraying everything in the room with mist.");

         set_exits(([
                     "north":ROOMS1"room-1d5.c",
                     "east":ROOMS1"room-1e6.c",
                     "south":ROOMS1"room-1d7.c",
                      "west":ROOMS1"room-1c6.c"
                     ]));
         set_items(([
                "whale":"May we please have a moment of silence of our friend here.... It's not going to last much longer."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
