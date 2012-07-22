#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "northwest" : ROOMS + "beach/68.c",
    "east" : ROOMS + "beach/93.c",
  ]));
}
