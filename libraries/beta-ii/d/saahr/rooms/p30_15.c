#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_14",
    "west" : VPROOMS "p29_15",
    "east" : VPROOMS "p31_15"
  ]));
}
