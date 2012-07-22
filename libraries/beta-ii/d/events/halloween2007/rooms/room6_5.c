#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "south" : H2K7ROOMS "room6_6",
    "southeast" : H2K7ROOMS "room7_6",
    "west" : H2K7ROOMS "room5_5",
    "east" : H2K7ROOMS "room7_5"
  ]));
}
