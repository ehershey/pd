#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The marsh ends suddenly as the path leads into a more open area.  A new path starts about a meter "
	"to the north and is composed of red and black interlocking stones.  There are a few bushes here but are "
	"mainly concentrated around the trees to the south and some indiscernable line in the north.");
    
    set_items(([
          "marsh" : "The marsh to the south seems to be a world away from here.",
	  "path" : "The path is made up of interlocking black and red stone.",
	  "line" : "Further north, the bushes form a line of some sort.  It's purpose is impossible to tell from here.",
	          
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "marsh57.c",
	"north" : ROOMS "tob2.c",
    ]));
}

