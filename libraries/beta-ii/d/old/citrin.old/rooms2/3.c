// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Citrin Forest");
set_long("The forest path turns wild and windy.  The "
"path curves to the southwest and east to avoid a huge "
"lake that has been formed over many years of rain and "
"erosion.");
set_items(([ 
"lake" : "The lake is a cystal blue color.  Many fish can "
"be seen jumping from inside its waters.",

"path" : "It is very windy.  It curves around to avois the "
"large lake to the south"

]));
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));

set_exits(([ "north" : ROOM2"2.c", "southwest" : ROOM2"4.c",
"east" : ROOM2"7.c",
]));

}
