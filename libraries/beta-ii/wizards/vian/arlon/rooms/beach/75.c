#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "beach/74.c",
    "northeast" : ROOMS + "beach/76.c",
  ]));
}
