#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("The white marble material here, as opposed to the material east of here, is showing gradual changes in its tone.  Its green outer-tinge has deepened, and in its core a second tinge of orange is beginning to surface.  There are potted flowers along the city walls, each on small pedestals of their own.  Stained-glass windows indicate housing of some kind in the upper part of the walls.  Chimes that have been suspended from wooden supports on the wall tops move back and forth in the gentle wind.");
    
    set_items(([
             ({"material", "stone", "stone material", "marble"}) : "The white marble is artifically tinged green.  The green is deeper here than in the east, and an orangey-brown tinge is growing in the heart of the stone.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.", 
               
    ]));

    set_listen("default", "The gentle sound of chimes can be heard on the wind.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis65.c",
        "east" : ROOMS "kesis68.c",
    ]));
}

