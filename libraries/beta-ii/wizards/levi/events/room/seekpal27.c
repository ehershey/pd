#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A hall");
    set_long("Many powerful looking weapons are hung here.  Scimitars, broadswords, longswords, cutlasses, "
	"even some jeweled scabbards line the walls.  They look quite deadly and magnificient under this "
	"blue light.  The walls are fairly plain to accommodate the weapons." );
    
    set_items(([
          "floor" : "The floor is black and shiny.  The weapons can be seen in it's surface...  also, what looks like a slender corridor can be seen only in the reflection...",
	  "walls" : "They are plain walls with armors lined against them.",
	  "light" : "Lanterns offer a comforting blue light.",
	  "weapons" : "The weapons look quite powerful.",
	  "corridor" : "It appears as though the corridor was positioned as a secret exit.", 	  
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "corridor" : ROOMS "seekpal28.c",
	"south" : ROOMS "seekpal26.c",	
        
       ]));
	add_invis_exit("corridor");
       
}

