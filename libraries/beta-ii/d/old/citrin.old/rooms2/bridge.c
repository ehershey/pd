// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("A rickety old bridge");
set_long("The water swooshes under neat the bridge causing water to spray "
"over the top of the bridge.  The bridge is pale colored from the weather.  "
"To the south is the mainland.  To the north is a small island in the middle "
"of the lake");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_listen("default", "The swooshing of water comes from under the bridge.");
set_items(([

"under bridge" : "It looks too be as if something lives under there.",
"island" : "The island is yet too far to be seen from here.",
"mainland" : "The mainland is too far to be seen from here.",
"bridge" : "This looks to be the only way to reach the island.  It looks "
	   "very old and worn.",
]));

set_exits(([
"south" : ROOM2"6.c",
"north" : ROOM2"island1.c",
]));


}

void init() {
::init();
add_action("catch_tell", "tell");
}

int catch_tell(string str) {
object a;

if (sscanf(str, "%s looks under bridge", a) == 1) {
write("This is a test");
}
}
