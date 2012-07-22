#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("This is a brief intersection.  Two alcoves in the walled street lead north and south and appear to be only moderately sheltered.  The street continues east and west.  Far to the east, beyond the great gate entrance, one can see the marina.  The view to the west is somewhat obstructed by high, defensive walls.  However, the rooftops of the tall buildings, all of them slate, dot the northwestern skyward view. ");
    
    set_items(([
             "gate" : "The massive gate is intricately composed of three dimensional, puzzle-like parts, with massive green doors that together look like a tortoise shell.",
             ({"material", "stone", "stone material", "marble"}) : "The white marble is artifically tinged green.  The rock takes on an unique look.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.", 
             "alcoves" : "The alcoves appear to be guard posts of some sort.",   
    ]));

    set_listen("default", "The gentle sound of chimes can be heard on the wind.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis66.c",
        "east" : ROOMS "kesis70.c",

        "north" : ROOMS "kesis67.c",
        "south" : ROOMS "kesis69.c",
    ]));
}

