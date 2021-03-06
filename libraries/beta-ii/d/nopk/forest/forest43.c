#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^YELLOW%^chestnut%^RESET%^ trees surrounds the "
      "area, their branches forming a green canopy of "
      "leaves that extend towards the sky.  The ground "
      "is scattered with fallen branches, and leaves.");
    set_exits( ([
      "east" : ROOMS+"forest42",
      "west" : ROOMS+"forest44",
      "north" : ROOMS+"forest38",
      "south" : ROOMS+"forest58"
    ]) );
}

void reset() {
    ::reset();

    if(!present("bobcat"))
	new(NPC+"bobcat.c")->move(this_object());
}
