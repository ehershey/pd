#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "docks/97.c",
    "east" : ROOMS + "docks/90.c",
  ]));
}
