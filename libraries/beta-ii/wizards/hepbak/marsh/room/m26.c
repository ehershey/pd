#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "m32",
"west" : ROOMS "m25",
"southwest" : ROOMS "m23",
    ]) );
}
