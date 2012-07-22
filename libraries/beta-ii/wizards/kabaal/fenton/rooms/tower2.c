#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 3, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The large, stone walls glisten in the candle light that originates from the room south "
      "of this one.  This room is bare and holds no apparent significance.  The same rugs "
      "lie on the floor, but that is all that inhabits this room.  "
    );
    set_items(([
        "walls" : "Large stone walls, yet somehow elegant.",
	"rugs" : "The rugs on the floor are royally embroidered.",
    ]));
   set_exits( ([ 
        "west" : ROOMS"tower3.c",
        "south" : ROOMS"tower1.c",
    ]) );
}
