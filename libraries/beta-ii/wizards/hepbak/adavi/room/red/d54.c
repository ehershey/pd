#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : RED "d55",
"west" : RED "d53",
    ]) );
}
