#include <kabaal.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a house");
set_long("This is the library of this small city. It is occupied by an elderly "
             "librarian. Many books line the walls, mostly fiction and mystery. "
	     "The library doesn't look like it gets much attention.");
set_property("building",1);
set_items(([
"books" : "Not much of interest...",
"shelves" : "Full of books",
"library" : "It doesn't look like it gets much use.",
]));
set_properties((["light" : 3, "night light" : 2,]));
set_exits(([
"out": ROOMS "logan7.c",
"up" : ROOMS "up1.c"
]));
}

void reset() {
::reset();
if(!present("librarian"))
new(MOB "librarian.c")->move(this_object());
}
