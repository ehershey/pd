
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside the city");
    set_long(
      "This shack is unlike the others.  It is a little bigger and well kept.  The "
      "floor is made up of wooden planks, the fireplace appears to be used often, and "
      "the walls are well painted and maintained. "
    );
    set_items(([
        "walls" : "Purty, huh?.",
        "floor" : "The floor has wooden planks on it.",
    ]));
   set_exits( ([ 
        "west" : ROOMS"ew1.c",
        "south" : ROOMS"room14.c",
    ]) );
}
