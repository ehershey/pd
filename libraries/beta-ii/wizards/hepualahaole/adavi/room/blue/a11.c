#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "a25",
"east" : BLUE "a12",
"west" : BLUE "a10",
    ]) );
}
