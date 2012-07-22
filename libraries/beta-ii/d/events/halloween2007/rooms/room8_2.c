#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "northwest" : H2K7ROOMS "room7_1",
    "southwest" : H2K7ROOMS "room7_3"
  ]));
}
