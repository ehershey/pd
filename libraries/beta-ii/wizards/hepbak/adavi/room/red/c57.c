#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : RED "c49",
"east" : RED "c58",
    ]) );
}
