#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : RED "c47",
"west" : RED "c52",
    ]) );
}
