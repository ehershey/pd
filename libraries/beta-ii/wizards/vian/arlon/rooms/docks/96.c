#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "docks/84.c",
    "north" : ROOMS + "roads/63.c"
  ]));
}
