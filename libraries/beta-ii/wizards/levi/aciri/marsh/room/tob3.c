#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("Large, breathtaking mountains are visible in the distance.  Clearly maintained hedge walls prevent any movement to the east or to "
	"the west.  There is a strange structure to the north with white and reddish walls.  An exit from this hedge path can be seen far to the "
	"south, almost invisible, a dark opening in the middle of the trees.  The path is composed of many interlocking black and red stones.");
    
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
        "south" : ROOMS "tob2.c",
	"north" : ROOMS "tob4.c",
    ]));
}

