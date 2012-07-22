#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Shrine Room");
    set_long("A large room can be seen to the north.  Here, the walls tower quite high opening "
	"into the large room ahead.  The floor is very shiny.  A soothing blue light shines down." );
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.",
	  "light" : "Lanterns offer a comforting blue light.",
	  	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "seekpal22.c",
	"north" : ROOMS "seekpal24.c",
	
        
       ]));
       
}


