#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh14",
"southeast" : ROOMS "marsh9",
"northeast" : ROOMS "marsh15",
"northwest" : ROOMS "marsh13",
"east" : ROOMS "marsh12",
    ]) );

}
