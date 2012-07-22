#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMO + "a1_2",
    "east" : ROOMO + "a2_1"
  ]));
}
