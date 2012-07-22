#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/78.c",
    "northwest" : ROOMS + "beach/70.c",
    "east" : ROOMS + "beach/68.c",
    "west" : ROOMS + "beach/76.c",
  ]));
}
