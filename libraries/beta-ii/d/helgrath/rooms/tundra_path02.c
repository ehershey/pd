#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Neverending Tundra");
    set_day_long("Huge snow drifts shift about in the gusting wind. small shrubs fight for survival "
      "in this frozen wasteland. The sun glares almost blindingly off of the icy white snow. "
      "Vast tundra stretches off to the horizon in every direction. " );
    set_night_long("Huge snow drifts shift about in the gusting wind. small shrubs fight for survival "
      "in this frozen wasteland. The moon reflects lazily off of the icy white snow. The numbing cold "
      "of the tundra theatens to stop blood flow. Vast tundra stretches off to the horizon in every direction. " );
    set_exits( ([ "north" : ROOMS "tundra_path01.c",
      "south" : ROOMS "tundra_path03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A fierce wind howls across the tundra.");

}
