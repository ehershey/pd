#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Tomb");
    set_long("The walls and floor are made of a brown rock, chiseled by primitive tools.  The ceiling is "
	"impossible to see in this light.  The northeastern is home to a massive arifact, a spider perhaps, "
	"if not for the huge hole broken into it's belly.  Light spills through the hole.  It appears that "
	"someone discovered a secret within.  There are no torches here.");
    
    set_items(([
          "walls" : "The walls of this area are chiseled out of brown rock.",
	  "artifact" : "The artifact is crafted to appear as a spider.  It has a huge hole in it's belly.",
    ]));
    set_properties(([
	"indoors" : 1,
	"light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "tob32.c",
	"west" : ROOMS "tob30.c",
    	"southwest" : ROOMS "tob31.c",
    ]));
}

