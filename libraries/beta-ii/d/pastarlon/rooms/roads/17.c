#include <std.h>
#include <pastarlon.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "square.c",
    "north" : ROOMS + "roads/18.c"
  ]));
}

