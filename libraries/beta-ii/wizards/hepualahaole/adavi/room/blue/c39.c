#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : BLUE "c40",
"west" : BLUE "c38",
    ]) );
}
