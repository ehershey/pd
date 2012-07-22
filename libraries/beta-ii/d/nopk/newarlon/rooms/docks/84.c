#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "beach/64.c",
    "west" : ROOMS + "beach/91.c",
    "north" : ROOMS + "docks/96.c",
    "south" : ROOMS + "docks/97.c",
    "east" : ROOMS + "docks/85.c",
  ]));
}
