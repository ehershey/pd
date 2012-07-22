#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "east" : ROOMS"room102",
                "west" : ROOMS"room100",
  ]) );
}