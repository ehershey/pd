#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "beach/81.c",
    "southwest" : ROOMS + "beach/83.c",
  ]));
}
