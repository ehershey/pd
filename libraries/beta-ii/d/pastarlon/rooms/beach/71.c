#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "beach/70.c",
    "west" : ROOMS + "beach/72.c",
  ]));
}
