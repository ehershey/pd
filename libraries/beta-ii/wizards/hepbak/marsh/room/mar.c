#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();


    set_exits( ([
"northwest" : ROOMS "mar6",
"east" : ROOMS "mar2",
"south" : ROOMS "ele21",
"southeast" : ROOMS "ele22",
    ]) );
}
