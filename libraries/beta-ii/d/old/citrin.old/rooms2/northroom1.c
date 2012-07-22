// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;
void reset() {
::reset();
if(!present("snake_citrin"))
new(MON2"snake")->move(this_object());

}

void create() {
::create();
set_name("A long path");
set_long("The path ends here leading no further to the north.  Many eyes "
"stare out from the bushes that surround this tiny area.  Several of the "
"eyes have a red glow to them.  Several tree branches have fallen here.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "Several branches lay on the ground",
(({"branches", "tree branches", "tree branch", "branch"})) : "Several "
"branches have fallen off of the trees.  They lay on the ground.",
(({"acorn", "acorns"})) : "The cover the path.  Many have holes caused by worms.",
]));

set_exits(([

"south" : ROOM2"14.c",
]));
}
