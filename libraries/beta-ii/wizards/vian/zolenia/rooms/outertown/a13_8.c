#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMO + "a13_9",
    "west" : ROOMO + "a12_8",
    "east" : ROOMO + "a14_8"
  ]));
}
