#include <std.h>
inherit ROOM;

void create () {
::create();
   set_short("tower5");
   set_long("This appears to be the room of a small time employee "
	"He is a very crazed employee.  He just sits ther behind his desk. "
	"It looks as if he were sharpening something there. UH-OH... RUN!!");
   set_items(([
	"desk" : "A normal desk, with a computer on it.",
	"computer" : "It looks like he was playing a very wellknown mud.",
]));
   set_properties(([
	"light" : 2,
	"night light" : 1,
]));
   set_exits(([
	"east" : "/wizards/manex/tower3.c",
]));
}
void reset() {
if(!present("company employee"))
        new("/wizards/manex/employee.c")->move(this_object());
}
