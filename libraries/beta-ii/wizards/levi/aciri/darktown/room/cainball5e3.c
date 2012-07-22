#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The great statue of the goddess is so large that it fills this area and most of the south.  From here, one could only see half of her. "
	     "The statue itself is crumbling apart.  In fact, a piece of her face and one of her fingers lies on the ground here but no one has "
	     "bothered to pick it up.  Blood runs down from the eyes of the goddess like a fountain and it would appear that she was praying to "
	     "another larger statue at the west end of the ballroom. ");


    set_items(([
	  "statue" : "It is quite clear now, the goddess is crying blood and praying toward a giant statue on the west wall.",        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"south" : ROOMS "cainball4e3.c",
	"west" : ROOMS "cainball5e2.c",
      ]));
}

void init() {
 ::init();
   add_action("statue", "climb");
}

int statue(string str) {
   if (!str || str != "statue") return notify_fail("Climb what?\n");
   write("You grab a part of the crumbling statue and slowly climb to the top of the head.");
   this_player()->move_player( ROOMS  "terratomb.c");
   return 1;
}


