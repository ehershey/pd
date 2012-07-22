#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "docks/85.c",
    "west" : ROOMS + "docks/100.c",
    "east" : ROOMS + "docks/89.c",
  ]));
}
