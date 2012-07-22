#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "north" : ROOMS + "docks/84.c",
    "west" : ROOMS + "beach/99.c",
    "east" : ROOMS + "docks/100.c",
    "south" : ROOMS + "docks/dock.c",
  ]));
}
