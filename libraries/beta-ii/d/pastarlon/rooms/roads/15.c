#include <std.h>
#include <pastarlon.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/14.c",
    "north" : ROOMS + "square.c"
  ]));
}

