#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("Blood has been spilled here many times and stains the amber "
	     "floor greatly.  A few discarded chalices, as if they were disposable "
	     "cups, have been discarded to the corner.  These vampires live like "
	     "kings.");


    set_items(([
	  "stains" : "The stains are from blood.  Someone has been drinking a lot.",
	  "chalices" : "Jeweled, silver and gold chalices have just been cast aside like paper cups.",
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"west" : ROOMS "cainball5.c",
        "east" : ROOMS "cainball5e2.c",
	"south" : ROOMS "cainball4e1.c",
       ]));
}


void reset() {
  ::reset();
    if(!present("noblevamp")) 
      new(MOB "noblevamp")->move(this_object());

}


