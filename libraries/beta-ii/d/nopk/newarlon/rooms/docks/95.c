#include <std.h>
#include <arlondocks.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "southeast" : ROOMS + "docks/86.c",
    "west" : ROOMS + "roads/63.c",
  ]));
}
