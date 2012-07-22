#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^GREEN%^hemlock%^RESET%^ trees create a "
      "sparse canopy of leaves, providing ample shade "
      "while admitting generous amounts of lighting "
      "during good weather.  The ground is scattered with "
      "fallen branches, and leaves.");
    set_exits ( ([
      "east" : ROOMS+"forest62",
      "west" : ROOMS+"forest64",
      "north" : ROOMS+"forest58",
      "south" : ROOMS+"forest78"
    ]) );
}

void reset() {
    ::reset();

    if(!present("bobcat"))
	new(NPC+"bobcat.c")->move(this_object());
}
