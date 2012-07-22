#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^GREEN%^pine%^RESET%^ trees surrounds the "
      "area, their branches forming a green canopy of "
      "leaves that extend towards the sky.  The ground "
      "is scattered with fallen branches, and leaves.");
    set_exits( ([
      "east" : ROOMS+"forest41",
      "west" : ROOMS+"forest43",
      "north" : ROOMS+"forest39",
      "south" : ROOMS+"forest59"
    ]) );
}

void reset() {
    ::reset();

    if(!present("woodchuck"))
	new(NPC+"woodchuck.c")->move(this_object());
}
