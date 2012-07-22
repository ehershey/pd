/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
     set_listen("","");
      set_smell("","");
       set_long("This part of the bay is totally serene."
                " There is a small raft floating here with some pelicans perched on it."
                " Some sealilies are clinging to the raft.");
        set_exits(([
                 "east":ROOMS1"room-1f5.c",
                 "southeast":ROOMS1"room-1f6.c",
                 "south":ROOMS1"room-1e6.c",
                 "west":ROOMS1"room-1d5.c",
                 "northwest":ROOMS1"room-1d4.c",
                 "north":ROOMS1"room-1e4.c"

                     ]));
         set_items(([
                "sealilies":"Typical water foliage.",
                 "raft":"A small craft with a couple of fisherman passed out on it."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
