#include <std.h>
#include <blueserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : BLUE "b6",
"northeast" : BLUE "b25",
    ]) );
}
