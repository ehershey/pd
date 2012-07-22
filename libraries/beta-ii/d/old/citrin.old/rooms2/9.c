// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Citrin Forest");
set_long("This path seems rather used by many traders that come here "
"to trade with the many cities to the east.  Serveral animal tracks "
"are here.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_items(([

"path" : "It is scattered with small animal footprints.",
(({"footprints", "footprint"})) : "They belong to many animals. Whatever "
"they were they left deep ruts.",
]));

set_exits(([
"north" : ROOM2"8.c",
"east" : ROOM2"dnest.c",
"south" : ROOM2"10.c",
]));
}
