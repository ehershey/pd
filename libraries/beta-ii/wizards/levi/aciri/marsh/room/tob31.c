#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Tomb");
    set_long("There is a semi-doorway here with many markings on it.  Torches can be seen within, lighting a few objects.  "
	"The substance that this tomb is made of seems to be some brown rock, chiseled into shape very poorly.  There is much "
	"dust and poor light.");
    
    set_items(([
          "torches" : "The torches are here to make the artifacts visible.",
	  "walls" : "The walls of this area are chiseled out of brown rock.",
	  "markings" : "Written in some very early language, it is impossible to tell what they say.",
    ]));
    set_properties(([
	"indoors" : 1,
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "northeast" : ROOMS "tob33.c",
	"east" : ROOMS "tob32.c",
    	"north" : ROOMS "tob30.c",
	"west" : ROOMS "tob29.c",
    ]));
}

