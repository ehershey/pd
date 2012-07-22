#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room11_8",
    "south" : H2K7ROOMS "room11_10",
    "east" : H2K7ROOMS "room12_9"
  ]));
}
