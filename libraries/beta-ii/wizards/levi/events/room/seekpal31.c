#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A corridor");
    set_long("The walls are a shade of grey here, normally white but not receiving enough light. "
	"To the north, there is a large doorway. ");
    
    set_items(([
          "walls" : "The walls are all white.",
	  "doorway" : "The doorway is fairly large, but it's just a black arch.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal32.c",
	"south" : ROOMS "seekpal30.c",
    ]));	
        
}

