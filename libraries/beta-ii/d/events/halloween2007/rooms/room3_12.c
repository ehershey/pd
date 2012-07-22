#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room3_13",
    "west" : H2K7ROOMS "room2_12",
    "east" : H2K7ROOMS "room4_12"
  ]));
}