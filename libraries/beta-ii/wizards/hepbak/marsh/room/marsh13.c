#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh18",
"southeast" : ROOMS "marsh11",
"northeast" : ROOMS "marsh19",
"northwest" : ROOMS "marsh17",
"south" : ROOMS "marsh10",
"east" : ROOMS "marsh14",
    ]) );
}
