#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "west" : H2K7ROOMS "room6_8",
    "east" : H2K7ROOMS "room8_8"
  ]));
}
