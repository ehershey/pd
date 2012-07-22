#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("There aren't any more chairs here but to the east there is a huge, "
	     "crumbling statue of a goddess on her knees praying.  This area seems "
	     "extremely quiet.");


    set_items(([
	  "statue" : "It is hard to make out the statue from here, the goddess can be seen on her knees, praying, but that is about all the detail you can see from here.",        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball5e2.c",
	"east" : ROOMS "cainball4e3.c",
	"west" : ROOMS "cainball4e1.c",
       ]));
}


