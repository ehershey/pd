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
      "of town. Shoveled snow lines the gutters, clearing the center of the road for "
      "pedestrians. To the south, the Gates of Yalth tower over the nearby buildings. " );
    set_exits( ([ "north" : ROOMS "yullblvd_s03.c",
      "south" : ROOMS "yullblvd_s05.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
