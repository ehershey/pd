/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The deafening roar of flowing water echos off the jette.");
         set_smell("default","Raw sewage permeates the area......");
        set_long("There is a large pipe sticking out of the jette."
                " A steady stream of sewage flows out of the pipe into the bay."
             " Numerous crawfish have gathered here to feast on the flow."
              "\n \nIt would be ill-advised for anyone to try swimming through this area.");

         add_invis_exit("crack");
         set_exits(([
        "east":"/d/nopk/tirun/beach/7,5,0",
                "north":ROOMS1"room-1g3.c",
                 "south":ROOMS1"room-1g5.c",
                 "crack":ROOMS1"secret-1.c",
                 "west":ROOMS1"room-1f4.c"
                     ]));
         set_items(([
                 "pipe":"The flow of sewage coming from the pipe is strong and constant.",
                 "sewage":"Disgusting.",
                 "jette":"It appears there is a crack large enough to squeeze through next to the pipe.",
                 "crawfish":"Countless crawfish have gathered to feast on the massive food supply."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
