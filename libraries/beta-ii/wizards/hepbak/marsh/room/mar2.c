#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "mar",
"east" : ROOMS "mar3",
"south" : ROOMS "ele22",
"southeast" : ROOMS "ele23",
"southwest" : ROOMS "ele21",
    ]) );
}

