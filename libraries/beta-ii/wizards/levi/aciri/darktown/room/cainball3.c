#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("Many people happily dance around.  Drinks have been spilled "
	     "all around the place and dancers drunkenly stumble around with "
	     "each other.  Riches of unbelievable value decorate vampires "
	     "who either sit and talk or dance.  The dancefloor is north of "
	     "here, but some may have forgotten where they were going .");


    set_items(([
	  "riches" : "Everyone is clad in many riches.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball4.c",
	"south" : ROOMS "cainball2.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("beautifulwoman")) 
      new(MOB "beautifulwoman")->move(this_object());


}
