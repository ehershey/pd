#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^GREEN%^hemlock%^RESET%^ trees surrounds the "
      "area, their branches forming a green canopy of "
      "leaves that extend towards the sky.  The ground "
      "is scattered with fallen branches, and leaves.");
    set_exits( ([
      "east" : ROOMS+"forest59",
      "west" : ROOMS+"forest57",
      "north" : ROOMS+"forest43",
      "south" : ROOMS+"forest63"
    ]) );
}

void reset() {
    ::reset();

    if(!present("squirrel"))
	new(NPC+"squirrel.c")->move(this_object());
}
