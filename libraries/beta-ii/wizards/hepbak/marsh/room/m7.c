#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "w",
"west" : ROOMS "m6",
"south" : ROOMS "marsh28",
    ]) );
}
