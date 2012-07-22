#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Tomb");
    set_long("This area appears to be some sort of underground tomb.  The walls are mostly dirt and rock fragments, giving the "
	"appearance of an area dug out of the earth.  A hall leads east, into a larger room lit by torches.  Wooden stairs lead "
	"up into an opening.");
    
    set_items(([
          "torches" : "The torches are in the east, lighting up the tomb.",
	  "walls" : "The walls of this area are all dirt and rock.",
	  "stairs" : "Wooden stairs, fairly new looking, have been placed here to provide an exit.",
    ]));
    set_properties(([
	"indoors" : 1,
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "up" : ROOMS "tob28.c",
	"east" : ROOMS "tob31.c",
    ]));
}

