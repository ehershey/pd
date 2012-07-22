#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "docks/86.c",
    "southeast" : ROOMS + "docks/90.c",
    "west" : ROOMS + "docks/84.c",
  ]));
}
