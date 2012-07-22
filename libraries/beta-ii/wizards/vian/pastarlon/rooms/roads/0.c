#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "west" : ROOMS + "roads/60.c",
    "east" : ROOMS + "roads/1.c",
    "north" : ROOMS + "roads/37.c",
    "south" : ROOMS + "roads/36.c",
  ]));
}
