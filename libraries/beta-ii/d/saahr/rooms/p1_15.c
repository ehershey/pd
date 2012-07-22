#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_14",
    "west" : VPROOMS "p0_15",
    "east" : VPROOMS "p2_15"
  ]));
}
