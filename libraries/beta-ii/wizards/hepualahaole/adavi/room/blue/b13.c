#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "b30",
"east" : BLUE "b14",
    ]) );
}
