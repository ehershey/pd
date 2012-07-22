#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard continues on to the north and south, winding its way through the various "
      "buildings along its path. Large snow drifts pile high against the building walls, having been blown "
      "there by the relentless wind. " );
    set_exits( ([ "north" : ROOMS "yullblvd_n05.c",
      "south" : ROOMS "yullblvd_n03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint humming noise can be heard.");

}
