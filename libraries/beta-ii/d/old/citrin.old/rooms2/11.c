// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("The edge of a large lake");
set_long("Part of the lake has seemed to rise coming very close to "
"the path.  Algea has overgrown the path due to the lake.  Several "
"tracks lay about from small animals.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "It is covered with algea.",
"algea" : "It covers the path.",
]));

set_exits(([

"east" : ROOM2"10.c",
"west" : ROOM2"12.c",
]));
}
