#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m22",
"northeast" : ROOMS "m23",
"west" : ROOMS "m17",
    ]) );
}
