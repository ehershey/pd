#include <std.h>
inherit ROOM;

void create () {
::create();
   set_short("a tower room");
   set_long("this is a room that is the security check #1.  there are three of "
	"these such rooms in this tower.  You should feel lucky, this room is "
	"mildly easy to get past. but the others, dont even think about yet. "
	"the others are way harder. and you need much more skill to pass them. "
	"yep, this one is pretty easy.");
   set_items(([
	"check" : "The check is a gate you pass, to see if you "
	"are carrying any illegal weapons.",
]));
   set_properties(([
	"light" : 2,
	"night light" : 1,
]));
   set_exits(([
	"up" : "/wizards/manex/tower7.c",
	"down" : "/wizards/manex/tower3.c",
]));
}
