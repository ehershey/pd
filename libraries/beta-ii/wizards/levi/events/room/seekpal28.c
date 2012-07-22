#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A corridor");
    set_long("The secret corridor looks nothing like the other halls.  It is extremely slender and short.  The walls, the ceiling "
	"and the floor are all a bright white colour. ");
    
    set_items(([
          "walls" : "The walls are all white.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "southwest" : ROOMS "seekpal27.c",
	"east" : ROOMS "seekpal29.c",	
    ]));
        
}

