#include <std.h>
#include <forest.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("In this part of the forest, trees grow "
      "in thick clusters.  The ground is scattered with "
      "fallen branches, and leaves.  A green canopy of "
      "leaves nearly blocks out the sky.");
    set_exits ( ([
      "east" : ROOMS+"forest32",
      "north" : ROOMS+"forest30",
      "south" : ROOMS+"forest50"
    ]) );
}

void reset() {
    ::reset();

    if(!present("elk"))
	new(NPC+"elk.c")->move(this_object());
}
