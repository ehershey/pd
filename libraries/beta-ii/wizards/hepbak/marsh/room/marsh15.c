#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh20",
"northeast" : ROOMS "marsh21",
"northwest" : ROOMS "marsh19",
"south" : ROOMS "marsh12",
"east" : ROOMS "marsh16",
"west" : ROOMS "marsh14",
"southwest" : ROOMS "marsh11",
    ]) );

}
