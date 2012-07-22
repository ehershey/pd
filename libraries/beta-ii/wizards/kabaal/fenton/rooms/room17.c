#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "The tower lies to the northwest. Large trees rise from the ground "
      "to the south and east. Several thick bushes line the path. A few "
      "run down houses lie northeast of here. "
    );
    set_items(([
        "tower" : "It stretches above the trees. ",
        "trees" : "They make up Fenton Woods.",
        "bushes" : "Thick bushes block passage to the south.",
        "path" : "It leads west and east.",
        "houses" : "Sad looking houses lie to the northeast.",
    ]));
   set_listen("default", "Birds can be heard overhead.");
   set_exits( ([ 
        "south" : ROOMS"room16.c",
        "northwest" : ROOMS"room19.c",
    ]) );
}
