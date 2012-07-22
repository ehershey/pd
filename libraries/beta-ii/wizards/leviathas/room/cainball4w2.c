#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("Just west of here is the foot of an awesome, black statue.  It's arms are crossed and it "
	     "looks down on the statue of the goddess who is patheticly begging it for solace.  Many "
	     "vampires and demons carved of stone claw at the feet of the statue and give praise to it. "
	     "A few vampires dancing near there have stopped and stare at it in awe.");


    set_items(([
	  "statue" : "Greater detail could be seen from the west.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball5w2.c",
	"east" : ROOMS "cainball4w1.c",
	"west" : ROOMS "cainball4w3.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("dancingman")) 
      new(MOB "dancingman")->move(this_object());

    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());
}
