#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A Garden");
    set_long("This is a rather strange looking garden full of many different plants of all shapes and kinds.  A couple of "
	"stone chairs have been placed in the garden, surrounded by stepping stones so that it is possible to enjoy the "
	"garden without destroying any of it's plants.  The hedge walls here are very tall.  Mountains can be seen to the "
	"north, towering high above.");
    
    set_items(([
          "walls" : "The hedge walls are rather high and thick, preventing travel through them.",
	  "stones" : "Stepping stones allow people to walk through the garden without damaging any of the plants.",
	  "structure" : "The structure to the north appears to be some sort of pyramid-shaped cocoon, red and white, almost pink.",
	  "mountains" : "Breathtaking, massive mountains that tower into the sky.",
	  "plants" : "The plants are very much alive and are incredibly diverse.  One particular bushel looks extremely withered.",
          "chairs" : "Stone chairs placed so that anyone can enjoy the beauty of the garden.",
	  "bushel" : "It would probably be possible to enter the area behind this bushel.",        
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "tob5.c",
    ]));
}


void init() {
 ::init();
   add_action("bushel", "enter");
}

int mansion(string str) {
   if (!str || str != "bushel") return notify_fail("Enter what?\n");
   write("You push the bushel and parts of it snap to let you pass.");
   this_player()->move_player( ROOMS  "tob25.c");
   return 1;
}
