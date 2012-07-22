#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Tomb");
    set_long("The walls and floor are made of a brown rock, chiseled by primitive tools.  The ceiling is "
	"impossible to see in this light.  On the southern and eastern walls, massive paintings have been "
	"uncovered.  They seem to depict some sort of scene.  There are torches on either wall that uncover "
	"the rich colours in these paintings.");
    
    set_items(([
          "torches" : "The torches are here to make the artifacts visible.",
	  "walls" : "The walls of this area are chiseled out of brown rock.",
	  "paintings" : "The wall paintings depict a massive beast looming over a heavily populated city.",
    ]));
    set_properties(([
	"indoors" : 1,
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "tob33.c",
	"west" : ROOMS "tob31.c",
    	"northwest" : ROOMS "tob30.c",
    ]));
}

