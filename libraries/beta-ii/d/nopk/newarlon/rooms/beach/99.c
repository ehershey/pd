#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "east" : ROOMS + "docks/97.c",
    "west" : ROOMS + "beach/92.c",
  ]));
}
