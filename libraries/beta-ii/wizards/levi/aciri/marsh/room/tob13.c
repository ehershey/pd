#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Temple of Change");
    set_long("This hall is very long and plain.  It is relatively featureless, if not for the subhalls leading east and west.  There appear "
	"to be large objects within the subhall and candles around them.  Light from the candles dances around the walls, giving the poorly "
	"lit hall some visibility.  At the end of the main hall there is an extremely large object with many candles around it.  The barely "
	"visible floor is very similar to marble.");
    
    set_items(([
          "floor" : "The floor seems to be made of marble.",
	  "subhalls" : "Subhalls lead east and west.",
	  "candles" : "Candles are placed around large objects which are too difficult to see from here.",
	  "objects" : "These large objects are not quite clear from here.",   
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "tob14.c",
	"east" : ROOMS "tob23.c",
	"west" : ROOMS "tob18.c",
	"south" : ROOMS "tob12.c",
    ]));
}

