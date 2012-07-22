#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh28",
"east" : ROOMS "marsh24",
"south" : ROOMS "marsh19",
"southwest" : ROOMS "marsh18",
"southeast" : ROOMS "marsh20",
"north" : ROOMS "marsh27",
"west" : ROOMS "marsh22",
    ]) );

}
