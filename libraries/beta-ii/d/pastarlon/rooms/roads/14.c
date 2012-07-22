#include <std.h>
#include <pastarlon.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/9.c",
    "north" : ROOMS + "roads/15.c"
  ]));
}

