#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("At the base of the statue.  It seems to tower up now and the face is lost behind the "
	     "folded arms.  The stone vampires look so real and everyone in the immidiate area has "
	     "stopped and kneeled.  Only half of the statue can be seen from here.");


    set_items(([
	  "statue" : "The statue is massive and perfect with no visible signs of ageing..",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball5w3.c",
	"east" : ROOMS "cainball4w2.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("dancingman")) 
      new(MOB "dancingman")->move(this_object());

    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());

    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());

    if(!present("oldking")) 
      new(MOB "oldking")->move(this_object());
}


void init() {
 ::init();
   add_action("statue", "climb");
}

int mansion(string str) {
   if (!str || str != "statue") return notify_fail("Climb what?\n");
   write("You walk past the others and grab something, attempting to climb the statue.  One of the stone vampires comes alive and casts you back.");
   this_player()->move_player( ROOMS  "cainball4w3.c");
   return 1;
}

