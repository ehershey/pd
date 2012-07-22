#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();

  set_exits(([
    "west" : ROOMS + "roads/4.c",
    "east" : ROOMS + "roads/6.c",
    "north" : ROOMS + "roads/28.c",
    "south" : ROOMS + "roads/29.c",
  ]));
}
