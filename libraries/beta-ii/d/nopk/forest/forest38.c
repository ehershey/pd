#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^WHITE%^elm%^RESET%^ trees create a "
      "sparse canopy of leaves, providing ample shade "
      "while admitting generous amounts of lighting "
      "during good weather.  The ground is scattered with "
      "fallen branches, and leaves.");
    set_exits ( ([
      "east" : ROOMS+"forest39",
      "west" : ROOMS+"forest37",
      "north" : ROOMS+"forest23",
      "south" : ROOMS+"forest43"
    ]) );
}

void reset() {
    ::reset();

    if(!present("mole"))
	new(NPC+"mole.c")->move(this_object());
}
