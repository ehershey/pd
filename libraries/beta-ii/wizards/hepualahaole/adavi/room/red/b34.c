#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : RED "b38",
"south" : RED "b27",
    ]) );
}
