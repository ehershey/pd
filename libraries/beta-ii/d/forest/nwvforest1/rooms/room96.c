#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north" : ROOMS"room103",
                "southwest" : ROOMS"room92",
  ]) );
}
