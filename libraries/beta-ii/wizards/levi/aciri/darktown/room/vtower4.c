#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A dead end.");
    set_day_long("%^MAGENTA%^Directly north of here lies a huge, stone door with "
               "blood dripping down from cracks in the design on it. "
               "To the east and west of this massive door lie two others, "
               "one gold and one silver.  There are names written in a "
               "language that is past your comprehension.  The floor is "
               "tiled with bone marrow and the walls surrounding the doors "
               "are jet black.  ");
   
    set_night_long("%^MAGENTA%^Directly north of here lies a huge, stone door with "
               "blood dripping down from cracks in the design on it. "
               "To the east and west of this massive door lie two others, "
               "one gold and one silver.  There are names written in a "
               "language that is past your comprehension.  The floor is "
               "tiled with bone marrow and the walls surrounding the doors "
               "are jet black.  ");
    
    set_items(([
	  "names" : "You cannot understand them",
          "stone door" : "It is huge. ",
          "gold door" : "This is a golden door, nothing more, nothing less. ",
          "silver door" : "This is a silver door, nothing more, nothing less. ",
              
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"south" : ROOMS "vtower3.c",
        "east" : ROOMS "balra1.c",
        "west" : ROOMS "vamp1.c",
        "north" : ROOMS "vtower5.c",
    ]));
    add_invis_exit("east");
    add_invis_exit("west");
    add_invis_exit("north");
    
}
