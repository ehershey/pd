#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A grey walkway");
    set_long("The grey structure can be seen in full.  It is an incredible building and totally unphased by the destruction around it.  "
	"The grey walkway which must have, at one time, been quite beautiful, is now smashed "
	"beyond repair.  It is the only way to cross to the massive, grey structure but it should be able "
	"to support a bit more beating. On either side of the walkway, a great pit can be seen.  Seemingly bottomless. ");
    
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
        "north" : ROOMS "seekpal10.c",
        "southwest" : ROOMS "seekpal8.c",
        
       ]));
       
}

