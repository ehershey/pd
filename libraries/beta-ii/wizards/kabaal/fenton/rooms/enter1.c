#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a shack");
    set_long(
      "This building is no more than a place to sleep.  You notice a kitchen-like "
      "room west.  Glancing around the room, you see a rugged staircase.  It  "
      "ventures up into the darkness. "
    );
    set_items(([
        "staircase" : "It doesn't look too awfully stable, but it should hold.",
        "kitchen" : "Not a whole lot too look at.",
    ]));
   set_listen("default", "The pitter-patter of little footsteps is heard.");
   set_exits( ([ 
        "out" : ROOMS"room7.c",
        "up" : ROOMS"enter3.c",
        "east" : ROOMS"enter2.c",
    ]) );
}
