#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room0_2",
    "south" : H2K7ROOMS "room0_4",
    "east" : H2K7ROOMS "room1_3"
  ]));
}
