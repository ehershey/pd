#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The hills of rock start here.  They are quite tall and in very good shape.  They look "
	"a lot like they were made an unimaginable force or a lot of hard work.  The path leads back "
	"east and northeast into the hills.");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "hills" : "The hills are made up of a grey rock slightly darker than that of the structure.",
	  "rock" : "The hills are made of a dark grey rock.",
	  "structure" : "An odd looking thing.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "northeast" : ROOMS "seekpal5.c",
        "east" : ROOMS "seekpal3.c",
        
       ]));
       
}

