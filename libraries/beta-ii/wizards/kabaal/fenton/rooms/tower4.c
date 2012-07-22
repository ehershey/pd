#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 3, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The room is baron except for the same royal carpeting as in the other rooms and a "
      "small plaque that lies on the eastern wall.  A staircase leads up into the darkness. "
    );
    set_items(([
	"rugs" : "The rugs on the floor are royally embroidered.",
	"staircase" : "It leads up into the darkness.",
    ]));
   set_exits( ([ 
        "up" : ROOMS"tower5.c",
        "north" : ROOMS"tower3.c",
    ]) );
}
void reset() {
::reset();
     if(!present("plaque.c"))
new(OBJ"plaque")->move(this_object());
}
