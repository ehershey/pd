#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "north" : ROOMO + "a15_9",
    "west" : ROOMO + "a14_10"
  ]));
}
