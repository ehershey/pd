#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "docks/95.c",
    "south" : ROOMS + "docks/96.c",
    "west" : ROOMS + "beach/81.c",
    "north" : ROOMS + "roads/62.c",
    "southwest" : ROOMS + "beach/64.c",
  ]));
}