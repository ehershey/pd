#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "docks/85.c",
    "west" : ROOMS + "docks/100.c",
    "east" : ROOMS + "docks/89.c",
  ]));
}
