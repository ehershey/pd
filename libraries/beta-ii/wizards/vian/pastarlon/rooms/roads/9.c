#include <std.h>
#include <pastarlon.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/61.c",
    "east" : ROOMS + "roads/10.c",
    "west" : ROOMS + "roads/8.c",
    "north" : ROOMS + "roads/14.c"
  ]));
}

