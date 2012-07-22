#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(DOCKSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "docks/88.c",
    "west" : ROOMS + "docks/90.c",
  ]));
}
