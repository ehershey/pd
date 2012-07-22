#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northeast" : ROOMS + "beach/67.c",
    "southeast" : ROOMS + "beach/94.c",
    "west" : ROOMS + "beach/69.c",
  ]));
}
