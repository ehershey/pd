#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "mar14",
"northwest" : ROOMS "mar13",
"east" : ROOMS "mar10",
"west" : ROOMS "mar8",
    ]) );
}
