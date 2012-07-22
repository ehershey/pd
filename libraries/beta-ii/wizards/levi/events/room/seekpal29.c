#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A corridor");
    set_long("The secret corridor looks nothing like the other halls.  It is extremely slender and short.  The walls, the ceiling "
	"and the floor are all a bright white colour.  With everything so white, it is extremely difficult to see any kind of exits "
        "or turns. ");
    
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
        "west" : ROOMS "seekpal28.c",
	"east" : ROOMS "seekpal30.c",	
    ]));
        
}

