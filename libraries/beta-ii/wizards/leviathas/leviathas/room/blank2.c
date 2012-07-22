#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Tower of the Deathless");
    set_long("This room is completely empty and painted white.");
    
    set_items(([
	"light" : "It's incredibly bright here.",                          
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"east" : ROOMS "vtower3.c",

    ]));
}
