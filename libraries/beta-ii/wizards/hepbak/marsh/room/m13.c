#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : ROOMS "m16",
"east" : ROOMS "m14",
    ]) );
}
