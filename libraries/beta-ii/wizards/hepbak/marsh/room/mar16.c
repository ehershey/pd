#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : ROOMS "mar11",
"west" : ROOMS "mar15",
"southeast" : ROOMS "mar12",
"southwest" : ROOMS "mar10",
    ]) );
}
