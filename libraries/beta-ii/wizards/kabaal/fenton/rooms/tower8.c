#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The staircase is of good size and leads up into the unknown.  The "
      "walls here are plain and cold.  A single candle levitates in the dead "
      "center of the room.   "
    );
    set_items(([
	"walls" : "The walls are cold stone. ",
	"staircase" : "It leads up into the unknown. ",
	"candle" : "A long slender candle floats in the middle of the room.",
    ]));
   set_listen("default", "Silence is broken by faint speaking.");
   set_exits( ([ 
        "up" : ROOMS"tower9.c",
        "east" : ROOMS"tower7.c",
    ]) );
}
void reset() {
::reset();
    if(!present("guardian.c"))
      new(MOB"guardian.c")->move(this_object());
      new(MOB"guardian.c")->move(this_object());
}
