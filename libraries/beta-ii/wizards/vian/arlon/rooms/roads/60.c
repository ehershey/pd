#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "east" : ROOMS + "roads/0.c",
  ]));
}
