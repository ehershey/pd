#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh27",
"east" : ROOMS "marsh23",
"south" : ROOMS "marsh18",
"southwest" : ROOMS "marsh17",
"southeast" : ROOMS "marsh19",
    ]) );

}
