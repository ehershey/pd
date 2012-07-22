#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "west" : ROOMS + "roads/0.c",
    "east" : ROOMS + "roads/2.c",
  ]));
}
