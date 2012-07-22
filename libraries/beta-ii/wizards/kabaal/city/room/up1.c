#include <kabaal.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a house");
set_long("This is the room in the library dedicated for the local residents to "
             "put stories that they've written. One book stands out on a table, as if "
	     "someone was recently reading.");
set_property("building",1);
set_items(([
"books" : "Not much of interest...",
"shelves" : "Full of books",
"library" : "The library is down from here."
]));
set_properties((["light" : 3, "night light" : 2,]));
set_exits(([
"down": ROOMS "en3.c"
]));
}

void reset() {
::reset();
if(!present("book"))
new(ITEMS "book.c")->move(this_object());
}
