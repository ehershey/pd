#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/64.c",
    "west" : ROOMS + "beach/79.c",
  ]));
}
