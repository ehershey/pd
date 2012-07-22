#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A clearing");
    set_long("This is a slight clearing surrounded by many bushes, trees and plants.  There is what could "
	"be described as a path to the west and a larger clearing in the east.  The sky is difficult to see "
	"with so many plants.");
    
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
        "east" : ROOMS "tob28.c",
	"west" : ROOMS "tob26.c",
    ]));
}

