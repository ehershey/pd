#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : ROOMS "mar",
"southwest" : ROOMS "marsh26",
"northeast" : ROOMS "mar8",
    ]) );

}
