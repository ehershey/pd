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
      set_long("");

         set_exits(([
                     ]));
         set_items(([
                 ]));
            new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
        MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
                      }
