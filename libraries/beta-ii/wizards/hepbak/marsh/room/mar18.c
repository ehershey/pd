#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : ROOMS "mar15",
"west" : ROOMS "mar17",
"southwest" : ROOMS "mar14",
"northeast" : ROOMS "mar22",
    ]) );

}
