// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("By a large lake");
set_long("This section is very bright from the large gaps in the "
"trees that grow here.  The are many acorns and leaves that fall "
"from the constant movement in the trees from the small animals "
"that live in side of them.  Several small footprints are on the path.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_items(([

"path" : "It is scattered with small animal footprints.  There is "
"also acorns laying about it.",
(({"footprints", "footprint"})) : "They belong to many animals. Whatever they were "
	       "they left deep ruts.",
]));

set_exits(([
"west" : ROOM2"3.c",
"southeast" : ROOM2"8.c",
]));
}
