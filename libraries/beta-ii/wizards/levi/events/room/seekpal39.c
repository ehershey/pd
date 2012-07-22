#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Great Solace");
    set_long("A bright red light is here, visible from this side of the room but not from the perspective of anyone who "
	"might be standing at the southern enterance staring north.  Warm air rushes out of the light, which continuously "
	"vibrates with activity.  The plants, extremely overgrown, cover the area around this light.  The soothing light "
	"seems to be focused around the red light and it's surroundings.");
    
    set_items(([
          "plants" : "Plants of all different shapes and kinds fill the area.",
	  "pool" : "The pool appears to be filled with a red blood that flows in an almost intelligent manner.",
	  "red lights" : "The red lights are are round and vibrate with activity.  They pump out a lot of warm air.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "seekpal37.c",
	"southeast" : ROOMS "seekpal36.c",
	"northeast" : ROOMS "seekpal38.c",
    ]));
}

