#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is a highly traversed road leading north to Helgrath Temple "
      "and south to the Gates of Yalth. Large snow drifts blockade the east building, "
      "climbing the wall to cover the awning overhead. " );
    set_exits( ([ "north" : ROOMS "yullblvd_n02.c",
      "south" : ROOMS "wilndursquare_mt" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint humming noise can be heard.");

}
