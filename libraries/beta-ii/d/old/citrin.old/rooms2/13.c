// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;
void reset() {
::reset();
if(!present("wolf"))
new(MON2"wolf2")->move(this_object());
}

void create() {
::create();
set_name("The edge of a large lake");
set_long("The path is very long.  It extends to the southeast and to "
"northeast.  Farther to the southeast is the deeper parts of the "
"forest.  The path is covered in small acorns from the trees "
"overhead");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "It is covered with acorns.",
(({"acorn", "acorns"})) : "The cover the path.  Many have holes caused by worms.",
]));

set_exits(([

"northwest" : ROOM2"10.c",
"southeast" : ROOM2"14.c",
]));
}
