#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^GREEN%^Garden of Darkness%^RESET%^");
    set_day_long("%^GREEN%^The garden is amazing.  Plants like no other on the surface of the world can be seen here.  The grass is perfect, the trees and the vines that grow around them are divine.  Truely, no being has stepped a foot here in a very long time.");
   
    set_night_long("%^GREEN%^The garden is amazing.  Plants like no other on the surface of the world can be seen here.  The grass is perfect, the trees and the vines that grow around them are divine.  Truely, no being has stepped a foot here in a very long time.");
    
    set_items(([
        "trees" : "The trees are simply wonderful.",
        "grass" : "Each blade of grass is simply perfect.  It's almost a shame to step on them.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "scrtgarden2.c",
	"south" : ROOMS "dtownm2.c",
	     
	 ]));
    
}


