#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The palace of Seeker");
    set_long("The waves create several exits here.  They form an amazing staircase to the north and "
	"two halls east and west.  The ceiling here is extremely low and the lights are very bright, "
	"making the walls look extremely real.  The black floor shines.");
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.",
	  "lights" : "Lanterns, particularly bright here.",
	  "staircase" : "The staircase must have taken months to create.  The detail is magnificient, somehow even beads of water are suspended in the air.",
	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "up" : ROOMS "seekpal21.c",
	"south" : ROOMS "seekpal19.c",
	"east" : ROOMS "seekpal25.c",
	"west" : ROOMS "seekpal22.c",
		
        
       ]));
       
}
