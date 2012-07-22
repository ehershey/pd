#include <std.h>
#include <arlon2.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/9.c",
    "north" : ROOMS + "roads/15.c"
  ]));
}

