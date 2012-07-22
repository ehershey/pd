#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The amber light shines still, reflecting off of pale, vampiric skin and actually making "
	     "it look human.  Some ghastly looking stairs can be seen to the east.");


    set_items(([
	  "statue" : "Not much to see here but it would be easier if you went west.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"west" : ROOMS "cainball5w3.c",
	"south" : ROOMS "cainball4w2.c",
	"east" : ROOMS "cainball5w1.c",
       ]));
}


void reset() {
  ::reset();
    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());

}


