#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("The Gates of the Sun");
    set_long("The west gate lies broken beside the wall.  Splinters of "
             "wood are scattered all about the area.  Deep tracks lead "
             "off to the west.  The city wall is quiet, no guards are around." );
    set_exits( ([ "east" : ROOMS "marketrd_w05.c",
      "west" : ROOMS "mountaint_s05.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "It is strangely quiet here..");

}
