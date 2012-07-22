#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room9_4",
    "east" : H2K7ROOMS "room10_3"
  ]));
}
