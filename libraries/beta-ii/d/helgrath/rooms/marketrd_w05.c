#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("The framework of a gate towers over the buildings just to "
             "the west.  The gate seems to be gone.  Tall, dark buildings "
             "crowd this narrow portion of the road, causing any passerby to "
             "dodge a bit to miss hitting the walls. " );
    set_exits( ([ "west" : ROOMS "marketrd_wgate.c",
      "east" : ROOMS "marketrd_w04.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A frigid breeze howls through the rooftops above.");

}
