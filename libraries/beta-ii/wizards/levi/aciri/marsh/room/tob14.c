#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Temple of Change");
    set_long("The hall comes to an abrupt end here.  There sits a massive statue of an old god, glorified in rays of light.  He looks very weary but is "
	"portrayed as a hero.  At his feet stand five figures about half his height, and at their feet thousands only a tenth of their height.  The floor "
	"seems worn here.");
    
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
        "east" : ROOMS "tob24.c",
	"west" : ROOMS "tob19.c",
	"south" : ROOMS "tob13 .c",
    ]));
}

