#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room9_12",
    "west" : H2K7ROOMS "room8_13",
    "east" : H2K7ROOMS "room10_13"
  ]));
}
