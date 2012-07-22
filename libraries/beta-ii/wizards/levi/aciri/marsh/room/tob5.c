#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The sheer size of the mountains is astounding.  Hedge walls allow two pathways leading to the east and to the west.  "
	"There appear to be gardens at the end of each path.  A massive structure is positioned in the north.  From here, it would "
	"appear that the structure was built into the mountain wall.  A path leads north and south, composed of black and red interlocking "
	"stones.");
    
    set_items(([
          "walls" : "The hedge walls are rather high and thick, preventing travel through them.",
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
        "south" : ROOMS "tob4.c",
	"north" : ROOMS "tob8.c",
	"east" : ROOMS "tob7.c",
	"west" : ROOMS "tob6.c",
    ]));
}

