#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room2_7",
    "west" : H2K7ROOMS "room1_6"
  ]));
}
