#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A grey walkway");
    set_long("The railing here has been torn off and to the north the walkway has even shattered to bits. "
	"Dim lights seem to protect the area, as the damage is less closer to the north."  );
    
    set_items(([
          "walkway" : "Utterly smashed, a great struggle must have occurred here.  It's impossible to %^RED%^walk%^RESET%^ any farther...",
	  "structure" : "It looks totally out of place, almost unreal.  It is totally unphased.",
	  "pit" : "The walkway seems to be made to cross the pit but it is in horrible shape.",
	  "divine fire" : "The divine fire burns on and on.",
	  "lights" : "The lights are close to where the damage has stopped.",
	  "railing" : "The railing has been torn to bits.",
	  
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal12.c",
	"south" : ROOMS "seekpal10.c",
        
       ]));
       
}


