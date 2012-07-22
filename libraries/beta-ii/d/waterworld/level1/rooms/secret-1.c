/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_smell("default","The stench from the sewer pipe is over-bearing to say the least...");
       set_listen("default","The roar of the pipe emptying into the bay is deafening!!");
       set_long(
          "A small room has been carved into the bedrock next to the sewage pipe that leads out into Tirun Bay."
                   " The floor is covered with small rocks and sand."
                  " There is also a large %^CYAN%^%^BOLD%^sign%^RESET%^ posted in the middle of the room.");

         set_exits(([
                  "up":"/d/nopk/newarlon/rooms/square",
                  "west":ROOMS1"room-1g4.c"
                     ]));
         set_items(([
                  "sign":
                "Dear Traveller,"
                "\n   For locating my humble home, I shall explain what i know about the clams and pearls to you."
                " First off, look at the clam to learn what kind of clam you are dealing with."
                 " Different clams can produce different pearls."
                 "\n  To look for pearls, You must dig in the sand where you located a clam."
                 "\n\nSincerly Heldalogala,"
                  "\n\nP.S. -- I haven't totally mastered what clams will give what pearls yet. You will have to figure that part out on your own"
                  ,"rocks":"A collection of rocks scattered around the cavern.",
                  "pipe":"A layer of %^GREEN%^slime%^RESET%^ oozes down the side of the pipe, falling into a darkened area below the pipe.."
                 ]));
            new(PEARLS"purple_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
//           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
