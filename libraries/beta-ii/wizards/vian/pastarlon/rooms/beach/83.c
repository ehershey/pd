#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/82.c",
    "southwest" : ROOMS + "beach/67.c",
  ]));
}
