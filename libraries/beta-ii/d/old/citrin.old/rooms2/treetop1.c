// Coding by Whit
// Coded for Primal Darkness
// treetop_1.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

//void init() {
//::init();
//add_action("swing_branch", "swing");
//}
void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("This is a small platform that was built to serve as a lookout
"
                 "for outlaws through the forest.  There is a small lamp
attached "
                 "to a branch to allow looking at things here when its dark.
The "
                 "sun streaks through here making this a bright spot.");
    set_night_long("This is a small platform that was built to serve as a
lookout "

                 "for outlaws through the forest.  There is a small lamp
attached "
                 "to a branch to allow looking at things here when its dark. 
The "
                 "stars shine clearly from here.");
new(OBJ"lantern1.c")->move(this_object());
    set_items(([
        "platform" : "The platform has turned a dark grey from the weather.",
          "branch" : "You may be able to swing on it.",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
"down" : ROOM2"2.c",
    ]));
}
//int swing_branch(string str) {
//  if(!str) {
//       notify_fail("Swing what?\n");
//        return 0;
//
//    }
//    if(str != "branch") {
//       notify_fail("You cant swing on that!\n");
//       return 0;
//    }
//
//write("You grab the branch and swing.");
//say(this_player()->query_cap_name()+" swings away.");
//this_player()->move_player("/d/citrin/rooms/treetop2");
//return 1;
//}
