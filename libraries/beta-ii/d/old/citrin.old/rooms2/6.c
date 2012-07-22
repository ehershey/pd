// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("By a large lake");
set_long("A large bridge is to the north.  It leads over the lake to "
"a small island on the lake.  The bridge looks sturdy.  The path is "
"cluttered with many small footprints.  Many acorns lay around.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_listen("default", "The sound of trickling water is near.");
set_items(([

"path" : "It curves near the water.  It is scattered with small "
         "animal footprints.  There is also acorns laying about it.",
(({"footprints", "footprint"})) : "They belong to many animals. Whatever they were "
	       "they left deep ruts.",
"bridge" : "This looks to be the only way to reach the island.  It looks "
	   "very old and worn.",
]));

set_exits(([
"northwest" : ROOM2"5.c",
"bridge" : ROOM2"bridge.c",
"east" : ROOM2"12.c",
]));
}
