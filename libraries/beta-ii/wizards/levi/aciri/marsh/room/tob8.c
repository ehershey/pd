#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("Entrance to the temple");
    set_long("The entrance to the massive cocoon-like structure is directly north.  The temple is very large, and it's walls move slightly with "
        "the pressure of the wind.  Two, very powerful looking Pillars brace the doorway.  Only darkness can be seen within.  As far as can be seen "
        "to the south, a long hedge wall dissapears into a line.");
    
    set_items(([
          "wall" : "The hedge wall is rather high and thick, preventing travel through them.",
          "structure" : "The structure to the north appears to be some sort of pyramid-shaped cocoon, red and white, almost pink.  It moves slightly in the wind.",
          "pillars" : "Mighty looking pillars, in cone shapes, Brace the doorway open.  They allow a person of any concievable size to enter the structure.",    
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "tob5.c",
    ]));
}


void init() {
 ::init();
   add_action("structure", "enter");
}

int structure(string str) {
   if (!str | str != "structure") return notify_fail("Enter what?\n");
   write("You pass into the darkness of the structure.");
   this_player()->move_player( ROOMS  "tob9.c");
   return 1;
}

