#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : BLUE "c48",
"northwest" : BLUE "c47",
    ]) );
}
