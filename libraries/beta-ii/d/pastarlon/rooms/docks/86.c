#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "docks/95.c",
    "east" : ROOMS + "docks/87.c",
    "southwest" : ROOMS + "docks/85.c",
  ]));
}
