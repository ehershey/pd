/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));

       set_long(
           " A large tidal pool covers most of the bay in this area."
            " The pool extends over twenty feet in depth and has a strong current flowing out of it."
            " Most adventurers would be hard pressed to keep from being washed out to sea."
                );
         set_exits(([
            "east":ROOMS1"room-1g6.c",
             "southeast":ROOMS1"room-1g7.c",
            "south":ROOMS1"room-1f7.c",
             "west":ROOMS1"room-1e6.c",
             "northwest":ROOMS1"room-1e5.c",
             "north":ROOMS1"room-1f5.c"
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
