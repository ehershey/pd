#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "southwest" : ROOMS + "beach/69.c",
    "east" : ROOMS + "beach/67.c",
  ]));
}
