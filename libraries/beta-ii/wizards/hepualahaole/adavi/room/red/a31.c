#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : RED "a38",
"south" : RED "a20",
    ]) );
}
