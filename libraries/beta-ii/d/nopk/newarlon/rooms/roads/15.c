#include <std.h>
#include <arlon2.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/14.c",
    "north" : ROOMS + "square.c"
  ]));
}

