#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "beach/94.c",
    "east" : ROOMS + "beach/92.c",
  ]));
}
