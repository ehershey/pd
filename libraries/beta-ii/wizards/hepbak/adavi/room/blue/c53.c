#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : BLUE "c68",
"southwest" : BLUE "c37",
    ]) );
}