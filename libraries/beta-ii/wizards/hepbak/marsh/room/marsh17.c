#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh22",
"east" : ROOMS "marsh18",
"southeast" : ROOMS "marsh13",
    ]) );
}
