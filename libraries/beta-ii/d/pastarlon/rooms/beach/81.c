#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "beach/82.c",
    "east" : ROOMS + "roads/63.c",
  ]));
}
