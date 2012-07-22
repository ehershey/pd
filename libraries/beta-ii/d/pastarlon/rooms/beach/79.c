#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "beach/67.c",
    "east" : ROOMS + "beach/80.c",
  ]));
}
