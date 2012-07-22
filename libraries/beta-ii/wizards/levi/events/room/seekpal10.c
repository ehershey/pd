#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A grey walkway");
    set_long("Closer to the structure, the damage to the walkway seems slightly less.  It almost "
	"looks like some protective force is guarding the structure and the area around it.  The "
	"pit seems to get deeper and deeper. ");
    
    set_items(([
          "walkway" : "Utterly smashed, a great struggle must have occurred here.",
	  "structure" : "It looks totally out of place, almost unreal.  It is totally unphased.",
	  "pit" : "The walkway seems to be made to cross the pit but it is in horrible shape.",
	  
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal11.c",
        "south" : ROOMS "seekpal9.c",
        
       ]));
       
}

