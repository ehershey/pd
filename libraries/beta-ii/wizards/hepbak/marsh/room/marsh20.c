#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh25",
"east" : ROOMS "marsh21",
"southeast" : ROOMS "marsh16",
"west" : ROOMS "marsh19",
"south" : ROOMS "marsh15",
"north" : ROOMS "marsh24",
"northwest" : ROOMS "marsh23",
"southwest" : ROOMS "marsh14",
    ]) );
}
