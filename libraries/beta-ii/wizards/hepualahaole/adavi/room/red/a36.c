#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : RED "a42",
"southwest" : RED "a28",
    ]) );
}
