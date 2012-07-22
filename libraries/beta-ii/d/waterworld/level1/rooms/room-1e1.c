/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear seagulls nearby.");
        set_smell("default","The smell of saltwater is very potent here.");
        set_long("This is one of the many tidal pools that fill this area."
                 " At the bottom of the pool are multiple discarded clam shells."
                 " You see a large congregation of birds off to the east."
                  " The vegetation to the north is dense and blocks any hope of travel that way.");

         set_exits(([
               "east":ROOMS1"room-1f1.c",
               "west":ROOMS1"room-1d1.c",
        "north":"/d/nopk/tirun/beach/4,1,0",
               "south":ROOMS1"room-1e2.c"
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
