#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "marsh21",
"west" : ROOMS "marsh25",
"northeast" : ROOMS "mar6",
    ]) );
}
