#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
	"light" : 2,
      ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is the main road leading north and south through the center "
      "of town. Shoveled snow lines the gutters. The Gates of Yalth Tower cast a menacing "
      "shadow over everything as they tower over the buildings just to the south. " );
    set_exits( ([ "north" : ROOMS "yullblvd_s04.c",
	"south" : ROOMS "yullblvd_sgate.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}

