#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "west" : ROOMO + "a11_1",
    "east" : ROOMO + "a13_1"
  ]));
}
