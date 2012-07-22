/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_listen("default","You hear a dolphin splashing back into the water after a jump.");
          set_long("This is another of the many tidal pools that litter this area.  Several forms of crabs and fish swim slowly at the bottom of the tidal pool.  There seems to be a whale beached here. Its tail rests here. The front half of the whale extends off to the east.");

         set_exits(([
                 "north":ROOMS1"room-1c5.c",
                  "east":ROOMS1"room-1d6.c",
                 "south":ROOMS1"room-1c7.c",
                  "west":ROOMS1"room-1b6.c"
                     ]));
         set_items(([
                "whale":"This is one sad whale. It seems it has come to realize its fate and given up hope.",
                 "dolphin":"A happy dolphin playfully jumping in and out of the water catching fish for dinner."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
