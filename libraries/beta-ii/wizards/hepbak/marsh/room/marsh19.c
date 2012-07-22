#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh24",
"east" : ROOMS "marsh20",
"southeast" : ROOMS "marsh15",
"west" : ROOMS "marsh18",
"south" : ROOMS "marsh14",
"north" : ROOMS "marsh23",
"northwest" : ROOMS "marsh22",
"southwest" : ROOMS "marsh13",
    ]) );
}
