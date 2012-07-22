#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
set_property("cave",1);
    set_short("Fenton City Limits");
    set_long(
      "Inside the cave, the temperature is quite comfortable.  The stone walls "
      "are drawn to your attention.  They harbor strange markings that look ancient. "
    );
    set_items(([
        "markings" : "Ancient symbols that you can't make out the meaning of.",
        "walls" : "The walls have strange markings on them.",
    ]));
   set_exits( ([ 
        "east" : ROOMS"cave3.c",
        "north" : ROOMS"cave2.c",
	"out" :ROOMS"hole.c",
    ]) );
}
