#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "west" : ROOMO + "a13_7",
    "east" : ROOMO + "a15_7"
  ]));
}
