#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "beach/73.c",
  ]));
}
