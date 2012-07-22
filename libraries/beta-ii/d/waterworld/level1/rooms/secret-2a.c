/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
      set_long("");
   set_long("Several tools are littered about the dock. A few ropes lie in one corner near the boat ties."
         " A large collection of fishing tackle litters the dock."
           " A pair of pelicans are fighting over a fish off to the eastern edge of the dock."
        " A shack of some kind garnishes the shore to the southeast of here."
         " There is also a towering lighthouse off to the west."
              );
         set_exits(([
                "ladder":ROOMS1"room-1c4.c"
                     ]));
         set_items(([
               "lighthouse":"You can see the outline of a lighthouse a good ways to the west of here.",
                "ropes":"A collection of standard issue ropes",
                "shack":"You can't make out much about it from here other than it lays a distance to the southeast.",
               "water":"You notice a cave at the bottom of the bay. Perhaps you can dive to it."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
void init() {
       ::init();
           add_action("secret", "dive");
}
int secret(string input) {
           if(!input || ((this_player()->query_level()) < 40)) return notify_fail("You dive onto the dock and flop around like a fish.\n");
           if (input != "water") return notify_fail("How do you propose we dive into THAT?\n");
                message("player", "You dive into the water and head for the cave. \n", this_player());
                 message("room",this_player()->query_cap_name()+" dives into the water! \n", environment(this_player()), this_player());
              this_player()->move(ROOMS1"secret-2b.c");
               message("room",this_player()->query_cap_name()+" swims into the cave.",environment(this_player()),this_player());
                 this_player()->force_me("look");
        return 1;
}
