#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "southwest" : ROOMS + "beach/75.c",
    "east" : ROOMS + "beach/69.c",
  ]));
}
