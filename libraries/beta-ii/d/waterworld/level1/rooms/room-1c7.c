/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
          set_listen("default","You hear the sound of seagulls squalking.");
            set_smell("default","You smell the leftover clams from the seagulls' feast last night.");
        set_long("This section of the shoreline is littered with clamshells in various stages of destruction and decay. It seems the seagulls had a feast last night when the tide went out. There are several pieces of driftwood bobbing in the ocean waves.");

         set_exits(([
             "east":ROOMS1"room-1d7.c",
              "west":ROOMS1"room-1b7.c",
              "north":ROOMS1"room-1c6.c",
                     ]));
         set_items(([
              "shells":"The empty shells of clams. Most are cracked open from birds feasting on them.",
              "waves":"The waves seem to beckon all who gaze upon them to join in their watery embrace.",
              "driftwood":"It's only a few decaying fragments of wood."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
