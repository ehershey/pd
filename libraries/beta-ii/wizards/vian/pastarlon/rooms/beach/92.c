#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/91.c",
    "west" : ROOMS + "beach/93.c",
    "east" : ROOMS + "beach/99.c",
  ]));
}
