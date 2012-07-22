#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "A few birds fly over head. The large tower blocks passage to the "
      "north. Thick bushes and trees line the southern direction. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"bushes" : "Thick bushes block passage to the south.",
	"path" : "It leads west and east.",
    ]));
   set_listen("default", "Birds can be heard overhead.");
   set_exits( ([ 
        "west" : ROOMS"room24.c",
        "east" : ROOMS"room26.c",
    ]) );
}
