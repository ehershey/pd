#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : ROOMS "marsh6",
"northeast" : ROOMS "marsh12",
"east" : ROOMS "marsh9",
"south"  : ROOMS "marsh5",
    ]) );
}
