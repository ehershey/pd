// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The path is littered with the leaves and twigs from the over head "
		 "trees.  Light shines through the tree tops making this area very "
		 "bright.  The sunshine gives off a orange glow as it hits the leaves.");
    set_night_long("The path is littered with the leaves and twigs from the over head "
		 "trees.  Light shines through the tree tops making this area very "
		 "bright.");
   set_listen("default", "The sound of crunching leves can be heard in the distance.");
	set_items(([
        "forest" : "The forest is thick with trees.",
        "sky" : "The sky can barely be seen though the tall trees.",
        "ground" : "The ground is littered with leaves and twigs from "
        "the tree braches above.",
        ({"leaves", "leaf", "twig", "twigs", "brach", "bracnches"}):
        "Leaves and twigs litter the ground.",
        ({"tree", "trees"}) : "The trees stretch high into the sky.",
	]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "north" : ROOMS+"openpath_5.c",
"south" : ROOMS"openpath_10.c",
    ]));
}
