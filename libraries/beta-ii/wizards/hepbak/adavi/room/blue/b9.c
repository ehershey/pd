#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : BLUE "b10",
"west" : BLUE "b8",
    ]) );
}
