#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A hall");
    set_long("A single window faces the southeast.  The walls are high here and the floor shines under the blue lights. " );
    
    set_items(([
          "floor" : "The floor is black and shiny.  It is very worn.",
	  "walls" : "They are plain walls with writings scratched into them",
	  "light" : "Lanterns offer a comforting blue light.",
	  "window" : "Outside the window, all that can be seen is a decimated jungle.",
	  	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal26.c",
	"west" : ROOMS "seekpal20.c",	
        
       ]));
       
}

