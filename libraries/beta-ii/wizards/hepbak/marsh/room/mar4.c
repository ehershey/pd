#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "mar3",
"east" : ROOMS "mar5",
"south" : ROOMS "ele24",
"southeast" : ROOMS "ele25",
"southwest" : ROOMS "ele23",
    ]) );
}
