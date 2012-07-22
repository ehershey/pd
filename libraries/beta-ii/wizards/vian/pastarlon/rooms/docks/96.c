#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "docks/84.c",
    "north" : ROOMS + "roads/63.c"
  ]));
}
