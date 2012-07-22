#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/67.c",
    "southeast" : ROOMS + "beach/94.c",
    "west" : ROOMS + "beach/69.c",
  ]));
}
