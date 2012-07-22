#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Tomb");
    set_long("A few torches light this massive, open room.  A large Talisman is built into the northwestern wall.  The walls and floor are "
	"made of a dull brown rock, chiseled into such by primitive tools.  The room is fairly dark, making it almost impossible to see the "
	"other corners of the room.");
    
    set_items(([
          "torches" : "The torches are here to make the artifacts visible.",
	  "walls" : "The walls of this area are chiseled out of brown rock.",
	  "talisman" : "A huge talisman is built into the side of the wall.  It is definitely an item with magical properties.",
    ]));
    set_properties(([
	"indoors" : 1,
	"light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "tob33.c",
	"southeast" : ROOMS "tob32.c",
    	"south" : ROOMS "tob31.c",
    ]));
}

