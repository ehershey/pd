#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "docks/95.c",
    "east" : ROOMS + "docks/87.c",
    "southwest" : ROOMS + "docks/85.c",
  ]));
}
