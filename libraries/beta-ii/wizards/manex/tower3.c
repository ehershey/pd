#include <std.h>
inherit ROOM;

void create() {
::create();
   set_short("Yet another tower");
   set_long("It is almost completely pitch black here, you cant even see your "
	"hand in front of your face.  Sweat is pouring off your body.  There "
	"is an incredible heat coming from your west.  To your east seems like "
	"some sort of lighter pathway. But there is always up.");
   set_items(([
   "ground" : "it is hot.",
]));
   set_properties(([
	"light" : 2,
	"night light" : 0,
]));
   set_exits(([
	"up" : "/wizards/manex/tower4.c",
	"west" : "/wizards/manex/tower5.c",
	"east" : "/wizards/manex/tower6.c",
	"down" : "/wizards/manex/tower2.c",
]));
}
