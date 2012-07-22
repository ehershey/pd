#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/83.c",
    "southeast" : ROOMS + "beach/79.c",
    "southwest" : ROOMS + "beach/68.c",
    "east" : ROOMS + "beach/66.c",
    "west" : ROOMS + "beach/78.c",
  ]));
}
