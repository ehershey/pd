#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
set_server(HOUSESERVER);
  ::create();
  set_exits(([
    "out" : ROOMS + "roads/32.c",
  ]));
}
