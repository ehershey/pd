#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "beach/69.c",
    "west" : ROOMS + "beach/71.c",
  ]));
}
