#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "beach/101.c",
    "northeast" : ROOMS + "beach/72.c",
    "southeast" : ROOMS + "beach/74.c",
  ]));
}
