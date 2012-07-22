
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "Candles hovering in mid air float around the room.  Magical energey "
      "is felt pretty strongly in this room.  The flames from the candles "
      "leave flickering shadows on the walls. "
    );
    set_items(([
	"walls" : "The candles leave shadows that make themselves at home here. ",
	"candles" : "Everlasting candles float in mid air.",
    ]));
   set_exits( ([ 
        "west" : ROOMS"tower8.c",
        "south" : ROOMS"tower6.c",
    ]) );
}

