#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "southwest" : ROOMS"room88",
                "north" : ROOMS"room97",
  ]) );
}
