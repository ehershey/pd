#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER2);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room11_3",
    "west" : H2K7ROOMS "room10_4",
    "east" : H2K7ROOMS "room12_4"
  ]));
}