#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : RED "a21",
"east" : RED "a8",
    ]) );
}
