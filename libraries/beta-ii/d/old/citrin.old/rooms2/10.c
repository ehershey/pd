// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Citrin Forest");
set_long("Several animal tracks are here.  This path is used by "
"animals as a way to reach the lake for there source of water.  "
"There are acorns laying about the path from the high above trees.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"acorns" : "They lay about the path.",
"path" : "It is scattered with acorns.",
]));

set_exits(([

"west" : ROOM2"11.c",
"southeast" : ROOM2"13.c",
"north" : ROOM2"9.c",
]));
}
