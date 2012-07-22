#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Shrine Room");
    set_long("A single window looks out southwest.  Decimated jungle can be seen through it.  A hall leads north and east.  The walls are very high and the "
	"floor is a shiny black.  A soothing light shines down." );
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.",
	  "light" : "Lanterns offer a comforting blue light.",
	  "window" : "Decimated jungle can be seen outside the window.",
	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "seekpal20.c",
	"north" : ROOMS "seekpal23.c",
	
        
       ]));
       
}

