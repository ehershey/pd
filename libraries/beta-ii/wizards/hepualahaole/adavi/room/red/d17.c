#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : RED "d22",
"southeast" : RED "d14",
    ]) );
}
