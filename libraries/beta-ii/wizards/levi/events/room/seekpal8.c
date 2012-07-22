#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("Divine fire is everywhere.  The end of this passage of rock has been utterly shattered. "
	"Divine fire this potient will scar the land for thousands of years.  A long, grey path leads "
	"northeast and north to the grey structure, only a quarter of which can be seen.");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "hills" : "The hills are made up of a grey rock slightly darker than that of the structure.",
	  "rock" : "The hills are made of a dark grey rock.",
	  "craters" : "They look like something big hit the wall.",
	  "ash" : "Something powerful must have went storming this way.",
	  "structure" : "Only a quarter of it can be seen here.",
	  "divine fire" : "It crackles, purple and red.  It looks quite evil.",
	  
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "northeast" : ROOMS "seekpal9.c",
        "south" : ROOMS "seekpal7.c",
        
       ]));
       
}

