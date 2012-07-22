#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The distance from here to the ceiling is astounding.  Vampires, at their own "
	     "leisure, are flying around, very high up.  It would seem that some red liquid "
	     "was dripping from the ceiling...");


    set_items(([
	  "ceiling" : "After looking for a few moments, you realize that on the ceiling there are several necks!  Vampires are flying up and drinking from them!!!",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"west" : ROOMS "cainball5w2.c",
	"east" : ROOMS "cainball5.c",
	"south" : ROOMS "cainball5w1.c",
       ]));
}


void reset() {
  ::reset();
    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());

}


