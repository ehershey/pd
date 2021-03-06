// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("A long path");
set_long("The path seems broken and uneven.  Plants have seem to regrow "
"over this once forgotten path.  Several animals footprints mark the path.  "
"Making this place an easy hunting ground for hunters.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "Several footprints of small animals cover the path.",
(({"branches", "tree branches", "tree branch", "branch"})) : "Several "
"branches have fallen off of the trees.  They lay on the ground.",
(({"acorn", "acorns"})) : "The cover the path.  Many have holes caused by worms.",
]));

set_exits(([

"south" : ROOM2"19",
"east" : ROOM2"15.c",
"west" : ROOM2"17.c",
// "south" : ROOM2"ecave.c",
]));
}
