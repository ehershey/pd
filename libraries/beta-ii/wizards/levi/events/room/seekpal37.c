#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Great Solace");
    set_long("Soothing lights shine all around.  A cool and yet warm breeze seems to constantly swim around the room.  Plants are all "
	"over the place, overgrown.  A pool of what appears to be blood shimmers at the ground.  The pool's substance shifts in an "
	"eerie way.");
    
    set_items(([
          "plants" : "Plants of all different shapes and kinds fill the area.",
	  "pool" : "The pool appears to be filled with a red blood that flows in an almost intelligent manner.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal38.c",
	"south" : ROOMS "seekpal36.c",
	"east" : ROOMS "seekpal40.c",
	"west" : ROOMS "seekpal39.c",
    ]));
}

