#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "m7",
"west" : ROOMS "m5",
"south" : ROOMS "marsh27",
"northeast" : ROOMS "m8",
    ]) );
}
