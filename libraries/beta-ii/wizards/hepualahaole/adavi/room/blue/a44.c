#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : BLUE "a34",
"east" : BLUE "a45",
    ]) );
}
