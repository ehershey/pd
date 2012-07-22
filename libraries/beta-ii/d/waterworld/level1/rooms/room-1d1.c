/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The sound of dolphins can be heard in the distance.");
      set_smell("default","The scent of seaweed hangs heavily in the air.");

       set_long(
             "The water here is about knee deep to the average human."
             " Several species of bait fish have set up their spawning grounds here."
             " Their nests are full of eggs with a few poking out of the soft sandy bottom."
             " Most of the nests are tended to by one or both of the parents."
             " There are several oysters and clams scattered about in the water."
                );
         set_exits(([
                "east":ROOMS1"room-1e1.c",
                "west":ROOMS1"room-1c1.c",
            "north": "/d/nopk/tirun/beach/3,1,0",
               "south":ROOMS1"room-1d2.c"
                     ]));
         set_items(([
                     "fish":"There are several fish here including bass and cods.",
                   "oysters":"Who has some cocktail sauce??",
                    "clams":"There is a large clam that catches your eye."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
