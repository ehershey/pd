#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "Dead leaves cover the ground.  Small stones lie about and small patches "
      "of dead grass can be here and there. Trees line the path, stopping "
      "adventurers from wandering west and south. The mage tower prevents "
      "access to the norteast. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"grass" : "Small patches of dead grass can be seen here and there.",
	"path" : "It leads north and south.",
	"stones" : "Small stones are scattered about on the ground.",
    ]));
   set_listen("default", "The leaves over head rustle in the wind.");
   set_exits( ([ 
        "north" : ROOMS"room23.c",
        "east" : ROOMS"room25.c",
    ]) );
}
