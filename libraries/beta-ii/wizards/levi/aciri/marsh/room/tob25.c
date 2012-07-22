#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A secret Path");
    set_long("This is a secret path behind dead bushes.  The sky is almost invisible behind so many bushes.  What might be a path leads east.  A "
	"clear exit is to the west.");
    
    set_items(([
          "bushes" : "The bushes are very dense, making it difficult to see the sky.",  
	  "path" : "What might be a path leads east.  It is difficult to tell.", 
    ]));
    set_properties(([
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "tob26.c",
	"west" : ROOMS "tob7.c",
    ]));
}

