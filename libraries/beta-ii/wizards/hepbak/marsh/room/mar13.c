#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : ROOMS "mar8",
"southeast" : ROOMS "mar9",
"east" : ROOMS "mar14",
    ]) );
}


