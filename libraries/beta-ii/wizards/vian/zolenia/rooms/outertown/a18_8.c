#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMO + "a18_9",
    "west" : ROOMO + "a17_8",
    "east" : ROOMO + "a19_8"
  ]));
}
