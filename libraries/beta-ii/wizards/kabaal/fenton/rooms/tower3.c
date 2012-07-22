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
      "gigantinc stone statue that rises from the floor. "
    );
    set_items(([
	"rugs" : "The rugs on the floor are royally embroidered.",
    ]));
   set_exits( ([ 
        "east" : ROOMS"tower2.c",
        "south" : ROOMS"tower4.c",
    ]) );
}
void reset() {
::reset();
     if(!present("statue.c"))
new(OBJ"statue")->move(this_object());
}
