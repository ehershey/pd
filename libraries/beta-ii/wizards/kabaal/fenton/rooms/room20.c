
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "Trees prevent you from going north while the tower prevents you from "
      "venturing south. The dirt path is old and dry. A few dry leaves "
      "cover the ground here. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"path" : "It is old and dry. It leads west and east.",
	"leaves" : "A few leaves cover the ground here.",
    ]));
   set_listen("default", "Birds chirping from the forest.");
   set_exits( ([ 
        "west" : ROOMS"room21.c",
        "east" : ROOMS"room19.c",
    ]) );
}
