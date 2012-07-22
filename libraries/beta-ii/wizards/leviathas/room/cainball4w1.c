#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("More people seem to be concentrated on this side of the ball.  Far east the statue of a praying Goddess "
	     "can be seen and not too far west an even bigger statue stares down on her.  Paintings of notable vampires "
	     "line the southern wall and the amber light would appear to be focused just below them.");


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
	"north" : ROOMS "cainball5w1.c",
	"east" : ROOMS "cainball4.c",
	"west" : ROOMS "cainball4w2.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("dancingman")) 
      new(MOB "dancingman")->move(this_object());

    if(!present("noblevamp")) 
      new(MOB "noblevamp")->move(this_object());
}
