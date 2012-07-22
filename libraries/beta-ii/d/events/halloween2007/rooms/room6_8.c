#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room6_7",
    "west" : H2K7ROOMS "room5_8",
    "east" : H2K7ROOMS "room7_8"
  ]));
}