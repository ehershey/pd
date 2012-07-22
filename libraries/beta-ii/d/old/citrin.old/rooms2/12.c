// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("The edge of a large lake");
set_long("A large lake is to the north.  It meets here with the path.  "
"Some algea has growed over the path making it slippery.  There are "
"small foot prints surrounding the path.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "It is covered with algea.",
"algea" : "It covers the path.",
]));

set_exits(([

"east" : ROOM2"11.c",
"west" : ROOM2"6.c",
]));
}
