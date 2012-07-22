#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "beach/81.c",
    "southwest" : ROOMS + "beach/83.c",
  ]));
}
