#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Shrine Room");
    set_long("Many small shrines have been started here by monks who are obsessed with the worship "
	"of their beloved Avatar.  Blue light still shines here. " );
    
    set_items(([
          "floor" : "The floor is black and shiny.",
	  "walls" : "They have been crafted to look like waves going up.",
	  "light" : "Lanterns offer a comforting blue light.",
	  "shrines" : "Little statuettes and sacrificial foods from little virgin damsels to their god.",
	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "seekpal14.c"	
        
       ]));
       
}


