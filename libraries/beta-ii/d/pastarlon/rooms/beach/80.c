#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/64.c",
    "west" : ROOMS + "beach/79.c",
  ]));
}
