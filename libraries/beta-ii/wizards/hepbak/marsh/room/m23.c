#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "m18",
"northeast" : ROOMS "m26",
"west" : ROOMS "m22",
    ]) );
}
