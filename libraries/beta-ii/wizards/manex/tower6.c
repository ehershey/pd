#include <std.h>
inherit ROOM;

void create() {
::create();
   set_short("tower6");
   set_long("This room belongs to a crazy deranged janitor.  The janitor looks "
	"like an ex-marine that you used to know.  The walls in this room are "
	"covered in small objects, and doo-dads.  Like many other people in "
	"this building, this janitor seems to have gone mad.  What could be "
	"the problem?");
   set_items(([
	"walls" : "The walls look like they have rags and brooms hanging on it.",
	"rags" : "stained rags.",
	"brooms" : "just normal brooms.",
	"doo-dads" : "just objects.",
]));
   set_properties(([
	"light" : 2,
	"night light" : 2,
]));
   set_exits(([
	"west" : "/wizards/manex/tower3.c",
]));
}
