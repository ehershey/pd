#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : BLUE "a30",
"east" : BLUE "a32",
    ]) );
}
