#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : RED "c46",
"south" : RED "c35",
    ]) );
}
