#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("Just east of here is the right side of a great goddess statue.  Detail from here "
	     "is pretty hard but it is crumbling.  This looks like a part of the ball that no one "
	     "has set foot in for a long time, it's brand new with none of the signs of ageing in "
	     "this ball.  Even the tiles are rather dim.");


    set_items(([
	  "tiles" : "They're dimmer on this side of the ball, perhaps to show how the goddess is lesser?",
	  "statue" : "A goddess praying, to whom it is too difficult to tell.",
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"west" : ROOMS "cainball5e1.c",
        "east" : ROOMS "cainball5e3.c",
	"south" : ROOMS "cainball4e2.c",
       ]));
}


void reset() {
  ::reset();
    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());

}


