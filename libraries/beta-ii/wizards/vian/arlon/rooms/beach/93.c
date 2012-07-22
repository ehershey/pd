#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "beach/94.c",
    "east" : ROOMS + "beach/92.c",
  ]));
}
