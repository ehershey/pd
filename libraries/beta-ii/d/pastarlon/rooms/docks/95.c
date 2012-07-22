#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "docks/86.c",
    "west" : ROOMS + "roads/63.c",
  ]));
}
