#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A corridor");
    set_long("Many bones that have been poorly swept away litter this part of the corridor.  The doorway is directly north and a dim, "
	"soothing light floods out.  It is fairly dark here, with little light of any kind. ");
    
    set_items(([
          "walls" : "The walls are all white.",
	  "doorway" : "The doorway is fairly large, but it's just a black arch.  A dim light comes through.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "enter" : ROOMS "seekpal33.c",
	"south" : ROOMS "seekpal31.c",	
    ]));
}

