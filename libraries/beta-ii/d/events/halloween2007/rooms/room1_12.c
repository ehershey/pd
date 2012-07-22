#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "west" : H2K7ROOMS "room0_12",
    "east" : H2K7ROOMS "room2_12"
  ]));
}