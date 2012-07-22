#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "docks/97.c",
    "east" : ROOMS + "docks/90.c",
  ]));
}
