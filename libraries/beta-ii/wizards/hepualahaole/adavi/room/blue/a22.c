#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "a35",
"northwest" : BLUE "a34",
    ]) );
}
