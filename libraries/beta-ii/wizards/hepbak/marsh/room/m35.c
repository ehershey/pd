#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "m36",
"west" : ROOMS "m34",
"south" : ROOMS "m27",
"southwest" : ROOMS "c1",
    ]) );
}
