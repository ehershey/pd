#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The dance floor starts here.  Vigorous shadows with blood running "
	     "down their chins move around with unhuman strength and grace.  Some "
	     "are floating and some are dancing on the ground together, all dressed "
	     "like royalty.  The floor here is tiled with amber and light from beneath "
	     "shines up, tinting much red.  The ceiling also curves up here, reaching far, "
	     "far up.");


    set_items(([
	  "tiles" : "The light beneath the amber tiles causes them to tint everyone an orangey-red.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball5.c",
	"east" : ROOMS "cainball4e1.c",
	"west" : ROOMS "cainball4w1.c",
	"south" : ROOMS "cainball3.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("dancinglady")) 
      new(MOB "dancinglady")->move(this_object());

    if(!present("noblevamp")) 
      new(MOB "noblevamp")->move(this_object());
}
