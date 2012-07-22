#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The palace of Seeker");
    set_long("Several black windows line this section of the hall.  It is difficult to see out of them but "
	"what little can be seen is a decimated jungle area.  The lights would seem to magnify the tint to the "
	"black windows, making it infinitely more difficult to see anything outside.  Not far north, a set of "
	"stairs can be seen.  The floor shines brilliantly.");
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.",
	  "lights" : "Lanterns offer a comforting blue light.",
	  "windows" : "The windows are tinted black.",
	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal20.c",
	"south" : ROOMS "seekpal18.c",
		
        
       ]));
       
}


