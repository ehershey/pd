#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "marsh25",
"south" : ROOMS "marsh20",
"southwest" : ROOMS "marsh19",
"southeast" : ROOMS "marsh21",
"north" : ROOMS "marsh28",
"west" : ROOMS "marsh23",
"northwest" : ROOMS "marsh27",
    ]) );
}
