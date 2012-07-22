#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The path of stone shows a little more wear here, compared to the seemingly never used southern half.  "
	"The bushes have grown much higher here and seem to have been cut into the shape of walls.  Far into the "
	"north, a strange structure can be seen.");
    
    set_items(([
          "bushes" : "The bushes have been cut into hedge walls.",
	  "path" : "The path is made up of interlocking black and red stone.",
	  "structure" : "The structure to the north is barely visible but appears to be pink.",
	          
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "tob1.c",
	"north" : ROOMS "tob3.c",
    ]));
}

