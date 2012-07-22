#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
   set_property("forest",1);
    set_long(
      "The small dirth path turns west here. It also continues onward "
      "north and south. A dead branch from a tree lies off the path. The "
      "large mage tower is now east of here. Trees lurch over head, shading "
      "the ground. A gentle breeze blows from the west, rustling the leaves. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"branch" : "A dead branch lies on the ground.",
	"path" : "It leads west, north, and south.",
    ]));
   set_listen("default", "The leaves over head rustle in the wind.");
   set_exits( ([ 
        "west" : ROOMS"forest1.c",
        "south" : ROOMS"room24.c",
        "north" : ROOMS"room22.c",
    ]) );
}
