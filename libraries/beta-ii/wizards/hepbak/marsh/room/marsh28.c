#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "marsh23",
"west" : ROOMS "marsh27",
"south" : ROOMS "marsh24",
    ]) );
}
