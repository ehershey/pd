#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "beach/82.c",
    "east" : ROOMS + "roads/63.c",
  ]));
}
