#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh8",
"east" : ROOMS "marsh6",
"southeast" : ROOMS "marsh3",
"northeast" : ROOMS "marsh9",
"south" : ROOMS "marsh2",
    ]) );

}
