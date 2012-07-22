#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A secret Path");
    set_long("There are a fair number of large, green bushes all around.  What might be a path leads west "
	"and a clearly defined path can be seen in the east, where much plantlife is trampled.");
    
    set_items(([
          "bushes" : "The bushes are very dense, making it difficult to see the sky.",  
	  "path" : "What might be a path leads west.  Also, an obvious path is in the east.", 
    ]));
    set_properties(([
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "tob27.c",
	"west" : ROOMS "tob25.c",
    ]));
}

