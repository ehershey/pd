#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "southwest" : ROOMS + "beach/92.c",
    "east" : ROOMS + "docks/84.c",
  ]));
}
