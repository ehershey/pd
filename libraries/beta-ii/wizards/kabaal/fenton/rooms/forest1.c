
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
   set_property("forest",1);
    set_short("fenton woods");
    set_long(
      "Trees shoot up from the ground around the path. A large tower can be "
      "seen to the east. The forest continues to the west, while civilization "
      "lies to the east. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"path" : "It leads west and east.",
    ]));
   set_listen("default", "Faint echoes of woodland creatures can be heard.");
   set_exits( ([ 
        "east" : ROOMS"room23.c",
        "west" : ROOMS"forest2.c",
    ]) );
}
void reset() {
::reset();
     if(!present("sign.c"))
new(OBJ"sign")->move(this_object());
}
