#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : ROOMS "marsh26",
"south" : ROOMS "marsh21",
"southwest" : ROOMS "marsh20",
"west" : ROOMS "marsh24",
    ]) );

}
