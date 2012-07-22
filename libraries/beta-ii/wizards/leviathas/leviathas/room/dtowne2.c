#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The road splits here, leading north, south, east or west.  A tall and skinny tower of a house with a door on one of it's edges stands to the northwest, a rectangular house to the southeast and a tiny box of a house to the southwest.  The darkness is dense.  ");
   
    set_night_long("%^BOLD%^%^BLACK%^The road splits here, leading north, south, east or west.  A tall and skinny tower of a house with a door on one of it's edges stands to the northwest, a rectangular house to the southeast and a tiny box of a house to the southwest.  The darkness is dense.  ");
    
    set_items(([
        "house1" : "The tall house resembles a tiny wooden tower.",
        "house3" : "The rectangular house is pretty old and rickety, with a balcony about 10 feet off the ground.",
	"mansion" : "The mansion could be considered a castle, if not for that eerie transylvanian look to it.",                  
        "house2" : "The square house .",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne1.c",
        "east" : ROOMS "dtowne3.c",
	"north" : ROOMS "dtowne2n.c",
	"south" : ROOMS "dtowne2s.c",
       ]));
    
}


