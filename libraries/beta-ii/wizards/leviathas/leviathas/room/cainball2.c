#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("All around, people are dancing and generally having fun. "
             "Some blood has been spilled off of a table here and waiters "
             "are busily cleaning it up.  The dishes, cuttlery and goblets "
	     "all look like they're worth an average house and everything "
             "in it.");


    set_items(([
	  "blood" : "Blood has been spilled here from a glass chalice.",
	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball3.c",
	"south" : ROOMS "cainball1.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("oldwomanvamp")) 
      new(MOB "oldwomanvamp")->move(this_object());
}
