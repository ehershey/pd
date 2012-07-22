/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","There is the sound of labored breathing coming from the south.");
      set_long("There seems to be a whale stuck in the bay a little ways to the south."
               " A large collection of seagulls are snoozing contently as they bob in the water."
               " A handful of pelicans are scattered into the collections of birds as well."
               " Not much else to see in this area besides the sleeping birds, water and fish."
                 );

         set_exits(([
                  "east":ROOMS1"room-1d5.c",
                  "northeast":ROOMS1"room-1d4.c",
                  "north":ROOMS1"room-1c4.c",
                  "west":ROOMS1"room-1b5.c",
                  "southwest":ROOMS1"room-1b6.c",
                  "south":ROOMS1"room-1c6.c"
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
