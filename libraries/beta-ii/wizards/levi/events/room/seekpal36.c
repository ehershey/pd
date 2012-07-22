#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Great Solace");
    set_long("This is the entrance to the Great Solace of the Avatar.  Calming lights shine all over the place.  Cool breezes constantly go by. "
	"A can be seen not far to the north, surrounded by green plants of all different sizes that seem to cover the entire room.  Smoke "
	"floats in from below.");
    
    set_items(([
          "staircase" : "The staircase is quite long but narrow.",
	  "plants" : "Plants of all different shapes and kinds fill the area.",
	  "pool" : "The pool seems to be red, and moving.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal37.c",
	"northeast" : ROOMS "seekpal40.c",
	"northwest" : ROOMS "seekpal39.c",
	"down" : ROOMS "seekpal35.c",
    ]));
}

