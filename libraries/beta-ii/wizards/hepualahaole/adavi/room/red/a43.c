#include <std.h>
#include <redserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : RED "a41",
"north" : RED "a46",
    ]) );
}
