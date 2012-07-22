#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "beach/71.c",
    "southwest" : ROOMS + "beach/73.c",
  ]));
}
