#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "beach/71.c",
    "southwest" : ROOMS + "beach/73.c",
  ]));
}
