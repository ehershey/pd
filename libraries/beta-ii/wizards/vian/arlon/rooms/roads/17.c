#include <std.h>
#include <arlon2.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "square.c",
    "north" : ROOMS + "roads/18.c"
  ]));
}

