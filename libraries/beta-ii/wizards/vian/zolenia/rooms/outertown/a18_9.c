#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "north" : ROOMO + "a18_8",
    "south" : ROOMO + "a18_10",
    "east" : ROOMO + "a19_9"
  ]));
}
