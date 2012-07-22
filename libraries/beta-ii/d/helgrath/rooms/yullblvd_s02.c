#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is a highly traversed road leading north and south through "
      "the center of the town. This section of the road is covered in snow, revealing the "
      " locations of the various citizens' routes as they move about their daily routines. " );
    set_exits( ([ "north" : ROOMS "yullblvd_s01.c",
      "south" : ROOMS "yullblvd_s03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
