#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "m6",
"west" : ROOMS "m4",
"south" : ROOMS "m3",
    ]) );
}
