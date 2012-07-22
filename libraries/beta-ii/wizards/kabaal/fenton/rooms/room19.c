#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "Outside the large tower, the path leads north west and southeast. A "
      "small mound of earth sticks up from the ground to the north. Trees "
      "stretch as far as the eye can see north and west. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"mound" : "A small dirt mound.",
    ]));
   set_listen("default", "Birds chirping from the forest.");
   set_exits( ([ 
        "west" : ROOMS"room20.c",
        "southeast" : ROOMS"room17.c",
    ]) );
}
