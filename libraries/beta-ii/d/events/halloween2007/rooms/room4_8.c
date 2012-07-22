#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room4_9",
    "west" : H2K7ROOMS "room3_8",
    "east" : H2K7ROOMS "room5_8"
  ]));
}
