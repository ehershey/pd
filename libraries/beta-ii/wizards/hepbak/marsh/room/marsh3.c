#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS   "marsh6",
"east" : ROOMS "marsh4",
"south" : ROOMS "marsh",
"west" : ROOMS "marsh2",
"northeast" : ROOMS "marsh7",
"northwest" : ROOMS "marsh5",
    ]) );

}
