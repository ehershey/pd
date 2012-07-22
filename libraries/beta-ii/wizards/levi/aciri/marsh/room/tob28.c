#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("A clearing");
    set_long("A large hole leads underground here.  Wooden steps descend into the dark, which have been placed "
	"to allow passage.  This clearing is rather large, but it is impossible to travel in any directions other "
	"than west, where there appears to be a slight path among the heavy plantlife.");
    
    set_items(([
          "bushes" : "The bushes are primarily concentrated in the west.  This is a clearing.",  
	  "path" : "What might be a path leads west.",
	  "clearing" : "The clearing does not appear to be man-made, rather it seems to have naturally formed around whatever the hole leads to.",
	  "steps" : "Wooden steps have been placed to allow travel into the hole.",
	  "hole" : "A large hole that leads down into the dark.",
    ]));
    set_properties(([
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "down" : ROOMS "tob29.c",
	"west" : ROOMS "tob27.c",
    ]));
}

