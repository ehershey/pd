#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "beach/69.c",
    "west" : ROOMS + "beach/71.c",
  ]));
}
