#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("Directly south of here are stairs leading up to a small "
             "door and to the north there are many vampires dancing about, "
	     "a waiter stands about a meter to the east.  Tables of mahogany "
	     "have been set up with golden chalices and silver cuttlery, "
	     "all of the food and drink being blood.  A great carpet leads "
	     "down the stairs, in between all of the tables, through the "
	     "center of the dance floor and up another set of stairs which "
	     "is identical to to the one south of here, if not for a peircing "
	     "darkness that defeats all surrounding light.  The light in this "
	     "area is fairly dim, a tranquil orange light.");


    set_items(([
	  "stairs" : "The stairs go north and south.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball2.c",
	"upstairs" : ROOMS "vhall3.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("waiter")) 
      new(MOB "waiter")->move(this_object());
}
