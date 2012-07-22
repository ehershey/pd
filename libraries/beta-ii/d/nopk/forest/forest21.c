#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^RED%^maple%^RESET%^ trees surrounds the "
      "area, their branches forming a green canopy of "
      "leaves that extend towards the sky.  The ground "
      "is scattered with fallen branches, and leaves.");
    set_exits( ([
      "west" : ROOMS+"forest22",
      "north" : ROOMS+"forest20",
      "south" : ROOMS+"forest40"
    ]) );
}

void reset() {
    ::reset();

    if(!present("puma"))
	new(NPC+"puma.c")->move(this_object());
}
