#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "docks/97.c",
    "west" : ROOMS + "beach/92.c",
  ]));
}
