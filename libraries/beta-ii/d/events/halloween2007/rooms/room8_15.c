#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room8_16",
    "west" : H2K7ROOMS "room7_15"
  ]));
}
