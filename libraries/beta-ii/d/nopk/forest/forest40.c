#include <std.h>
#include <forest.h>
#include <ansi.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( (["forest" : 1, "outdoors" : 1, "light" : 3]) );
    set_short("Forest");
    set_long("This is a dense part of the forest.  A "
      "grove of %^BOLD%^%^WHITE%^elm%^RESET%^ trees surrounds the "
      "area, their branches forming a green canopy of "
      "leaves that extend towards the sky.  The ground "
      "is scattered with fallen branches, and leaves.");
    set_exits( ([
      "west" : ROOMS+"forest39",
      "north" : ROOMS+"forest21",
      "south" : ROOMS+"forest41"
    ]) );
}

void reset() {
    ::reset();

    if(!present("porcupine"))
	new(NPC+"porcupine.c")->move(this_object());
}
