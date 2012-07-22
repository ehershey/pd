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
                " It appears the raft isn't anchored to the bay floor however."
                " Some sealilies are clinging to the raft.");

         set_exits(([
          "east":ROOMS1"room-1c2.c",
          "southeast":ROOMS1"room-1c3.c",
          "south":ROOMS1"room-1b3.c",
          "west":ROOMS1"room-1a2.c",
          "northwest":ROOMS1"room-1a1.c",
          "north":ROOMS1"room-1a1.c"
                     ]));
         set_items(([
                "sealilies":"Typical water foliage.",
                 "raft":"A small craft with a couple of fishermen passed out on it."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
