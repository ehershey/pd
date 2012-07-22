#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room3_15",
    "west" : H2K7ROOMS "room2_16",
    "east" : H2K7ROOMS "room4_16"
  ]));
}
