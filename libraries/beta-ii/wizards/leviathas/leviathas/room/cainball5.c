#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The stairs leading into darkness are directly north of here. "
	     "East and west people are talking and drinking their chalices "
	     "and goblets of wine, ignoring the darkness that seems to get "
	     "louder.");


    set_items(([
	  "stairs" : "They look much less inviting than the ones to the south.  Why could that be?",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"stairs" : ROOMS "stairstocain.c",
	"east" : ROOMS "cainball5e1.c",
	"west" : ROOMS "cainball5w1.c",
	"south" : ROOMS "cainball4.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("dancinglady")) 
      new(MOB "dancinglady")->move(this_object());

    if(!present("oldking")) 
      new(MOB "oldking")->move(this_object());
}
