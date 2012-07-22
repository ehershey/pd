#include <kabaal.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a house");
set_long("This house is in pretty bad shape. The ceiling is crumbling and looks "
             "as though it is ready to collapse at any time. Several bare shelves "
	     "line the walls. The occupants of this house appear to be pretty poor.");
set_property("plain",1);
set_items(([
"ceiling" : "The ceiling is peeling and crumbling. It could collapse at any time.",
"shelves" : "Empty...",
"building" : "It's seen better days.",
]));
set_properties((["light" : 3, "night light" : 2,]));
set_exits(([
"out": ROOMS "logan4.c"
]));
}

void reset() {
::reset();
if(!present("citizen"))
new(MOB "lc1.c")->move(this_object());
}
