#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "docks/88.c",
    "west" : ROOMS + "docks/86.c",
  ]));
}
