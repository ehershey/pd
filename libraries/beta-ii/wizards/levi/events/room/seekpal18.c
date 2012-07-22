#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The palace of Seeker");
    set_long("Many faces have been worked into the sculpted wave-like walls.  They appear to be honorable "
	"warriors of the past, portrayed as god-like beings.  There seem to be a few more spaces, as if only "
	"a couple more warriors are expected to do anything notable.  The floor is very shiny and compliments "
	"the walls quite nicely.  The lights continue to pour down in a soothing manner.");
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.  Several faces have been carved into them.",
	  "lights" : "Lanterns offer a comforting blue light.",
	  "faces" : "Many faces of slain warriors.",
	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal19.c",
	"south" : ROOMS "seekpal14.c",
		
        
       ]));
       
}


