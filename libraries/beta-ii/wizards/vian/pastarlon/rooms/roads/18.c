#include <std.h>
#include <pastarlon.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/17.c"
  ]));
}

