#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^GREEN%^Garden of Darkness%^RESET%^");
    set_day_long("%^GREEN%^The beauty of the garden is undeniable.  A tiny shaft of light comes through the trees and shimmers on some rocks with dew on them.  The stone building to the north can be seen quite clearly now.  It is similar to a pyramid but much narrower.  Plants grow densely here.");
   
    set_night_long("%^GREEN%^The beauty of the garden is undeniable.  A tiny shaft of light comes through the trees and shimmers on some rocks with dew on them.  The stone building to the north can be seen quite clearly now.  It is similar to a pyramid but much narrower.  Plants grow densely here.");
    
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
        "north" : ROOMS "scrtgarden4.c",
	"south" : ROOMS "scrtgarden2.c",
	     
	 ]));
    
}


