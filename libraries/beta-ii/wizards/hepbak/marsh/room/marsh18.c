#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh23",
"east" : ROOMS "marsh19",
"southeast" : ROOMS "marsh14",
"west" : ROOMS "marsh17",
"south" : ROOMS "marsh13",
"north" : ROOMS "marsh22",
    ]) );

}
