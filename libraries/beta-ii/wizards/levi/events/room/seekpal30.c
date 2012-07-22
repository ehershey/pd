#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A corridor");
    set_long("The secret corridor ends not far to the north, where there appears to be a black, doorless entrance to something.  The "
	"white of the corridor is slightly darker here from the shadows. ");
    
    set_items(([
          "walls" : "The walls are all white.",
	  "doorway" : "The doorway is barely visible, but it's just a black arch.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "seekpal29.c",
	"north" : ROOMS "seekpal31.c",
    ]));
        
}

