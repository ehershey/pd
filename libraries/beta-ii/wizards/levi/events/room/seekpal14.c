#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
    ::create();
    set_short("The palace of The Avatar");
    set_long("The wave ripples in the walls that open up in four directions here. To the west, there is a "
      "have been a shop of some kind, but has caved in.  East, a series of small sacrifices.  North, the hall continues and south is the rather large "
      "exit.  A cool light shines down, extremely soothing.");

    set_items(([
	"floor" : "The floor is black and shiny.",
	"walls" : "They have been crafted to look like waves going up. 
Several faces have been carved into them.",
          "light" : "Lanterns offer a comforting blue light.",
          
          
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal18.c",
        "south" : ROOMS "seekpal13.c",
        "east" : ROOMS "seekpal15.c"
                        
        
       ]));
       
}
