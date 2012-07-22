#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The path leads east and west.  "
	"From here, black windows can be seen on the structure to the north barely through "
	"a gap in the hills of rock.  Rocks now cover the ground almost completely.  A little "
	"hole is half hidden by grass here. ");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "windows" : "The black windows stand out a lot.",
	  "rock" : "The hills are made of a dark grey rock.",
	  "structure" : "An odd looking thing.",
	  "hole" : "A little animal's home.",
	  "grass" : "A tiny bit of grass covers the hole.",      
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "seekpal4.c",
        "east" : ROOMS "seekpal2.c",
        
       ]));
       
}

