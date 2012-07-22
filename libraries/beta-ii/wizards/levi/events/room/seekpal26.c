#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A hall");
    set_long("Fine armors line the walls.  Different types of platemail from all around the "
	"world.  They must all be blessed by the Avatar.  They can be seen in the floor's shiny "
	"reflective surface.  The walls are rather basic to accommodate the armor." );
    
    set_items(([
          "floor" : "The floor is black and shiny.  The armors can be seen in it's surface.",
	  "walls" : "They are plain walls with armors lined against them.",
	  "light" : "Lanterns offer a comforting blue light.",
	  "armors" : "The armors look quite durable.",
	  	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal27.c",
	"south" : ROOMS "seekpal25.c",	
        
       ]));
       
}

