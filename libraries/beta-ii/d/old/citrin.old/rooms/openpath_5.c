// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The path suddenly turns dark from the shade of the mighty oak that "
		 "grows to the west.  Many hideous things live on this side forest "
		 "of the forest.  Most of the sunlight that makes its way around the "
		 "tree lights up some of the path making it visible to walk. ");
    set_night_long("The path suddenly turns dark from the shade of the mighty oak that "
		 "grows to the west.  Many hideous things live on this side forest "
		 "of the forest.  Most of the light that makes its way around the "
		 "tree lights up some of the path making it visible to walk. ");

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
        "southwest" : ROOMS+"openpath_4.c",
        "southeast" : ROOMS+"openpath_7.c",
	"south" : ROOMS+"openpath_6.c",
    ]));
}
