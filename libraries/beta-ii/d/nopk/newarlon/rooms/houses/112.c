#include <std.h>
#include <arlonhouses.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "out" : ROOMS + "roads/30.c",
  ]));
}

