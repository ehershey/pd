/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_short("Shoreline");
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear the relaxing sound of waves breaking on the sandy beach.");
        set_smell("default","You smell the strong scent of salt water in the air.");

        set_long("This is the breakwaters leading out into open ocean."
               " The channel is about waist deep in water and is hard"
                " for anything to maintain their footing due to the strong undertow."
                 " A multitude of sea creatures are swimming around in the channel."
                     );
         set_exits(([
                "east":ROOMS1"room-1e7.c",
                "west":ROOMS1"room-1c7.c",
                "north":ROOMS1"room-1d6.c"
                     ]));
         set_items(([
                    "waves":"You bob gently in the waves as they roll past you.",
             "shore":"That is the sandy shore leading back to the dry lands of Tirun City.",
              "creatures":"You see numerous life forms in all shapes and sizes.",
              "clams":"You see some clams here. Some even have pearls in them.  Perhaps if you were to -dig sand- you might find some more pearls."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
            MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
