#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "west" : ROOMS + "roads/0.c",
    "east" : ROOMS + "roads/2.c",
  ]));
}
