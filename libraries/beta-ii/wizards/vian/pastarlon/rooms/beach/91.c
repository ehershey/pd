#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "southwest" : ROOMS + "beach/92.c",
    "east" : ROOMS + "docks/84.c",
  ]));
}
