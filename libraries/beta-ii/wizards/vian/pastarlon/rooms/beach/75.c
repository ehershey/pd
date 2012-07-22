#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(BEACHSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "beach/74.c",
    "northeast" : ROOMS + "beach/76.c",
  ]));
}
