#include <std.h>
#include <arlon2.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/61.c",
    "east" : ROOMS + "roads/10.c",
    "west" : ROOMS + "roads/8.c",
    "north" : ROOMS + "roads/14.c"
  ]));
}

