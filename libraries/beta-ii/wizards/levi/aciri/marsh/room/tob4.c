#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("Massive mountains consume all of the north.  Hedge walls block any directions other than north and south.  "
	"There appears to be a small opening in the trees to the south at the end of the path, which is composed of red "
	"and black interlocking stones.  To the north, there stands a massive, pyramid-cocoonlike structure of some sort.  "
	"Not far north, the path divides into four different directions.");
    
    set_items(([
          "bushes" : "The bushes have been cut into hedge walls.",
	  "path" : "The path is made up of interlocking black and red stone.",
	  "structure" : "The structure to the north appears to be some sort of pyramid-shaped cocoon, red and white, almost pink.",
	  "mountains" : "Breathtaking, massive mountains that tower into the sky.",         
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "tob3.c",
	"north" : ROOMS "tob5.c",
    ]));
}

