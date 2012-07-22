#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The path returns south and jerks to the west.  "
	"Far to the north there is a large grey structure.  It is fairly difficult to make out "
	"from here as large hills of rock block most of it's view.  The hills look like they have "
	"been cut out by some extremely precise means. ");
    
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
        "west" : ROOMS "seekpal3.c",
        "south" : ROOMS "seekpal1.c",
        
       ]));
       
}

