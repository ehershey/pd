#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : BLUE "a33",
"southeast" : BLUE "34",
    ]) );
}