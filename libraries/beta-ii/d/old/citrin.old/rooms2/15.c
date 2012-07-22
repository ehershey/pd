// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("A long path");
set_long("The path has been overgrown with a %^GREEN%^green%^RESET%^ "
"foliage.  Woods lead to the north making it imposible to "
"cross.  Small light can be seen overhead.  The trees here seem to "
"lash out at you.  There seems to be a large clearing to the south.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "This is a well used path.  Several foot prints can be seen "
"here.",
(({ "foot prints", "prints" })) : "They belong to small animals.  "
"However there seems to be a large set of foot prints next to them. ",
]));

set_exits(([

"northwest" : ROOM2"14.c",
"west" : ROOM2"16.c",
]));
}
