#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room7_11",
    "west" : H2K7ROOMS "room6_12",
    "east" : H2K7ROOMS "room8_12"
  ]));
}
