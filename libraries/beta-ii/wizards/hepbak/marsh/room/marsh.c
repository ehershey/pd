#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

    set_exits( ([
"north" : ROOMS "marsh3",
"northeast" : ROOMS "marsh4",
"northwest" : ROOMS "marsh2",
"south" : ROOMS "docks3",
    ]) );
}
