#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "mar2",
"east" : ROOMS "mar4",
"south" : ROOMS "ele23",
"southeast" : ROOMS "ele24",
"southwest" : ROOMS "ele22",
    ]) );

}
