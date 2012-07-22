#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "Trees block the path from going north and west. A small puddle "
      "of water lies here. To the south east the tower stretches into the "
      "sky.  A pitiful attempt at a flower garden rests between the path "
      "and the tower. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"path" : "It is old and dry. It leads west and east.",
	"garden" : "Dead flowers lie in the garden.",
	"puddle" : "A small puddle of water with no significance.",
    ]));
   set_listen("default", "Birds chirping from the forest.");
   set_exits( ([ 
        "east" : ROOMS"room20.c",
        "south" : ROOMS"room22.c",
    ]) );
}
