#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "west" : ROOMO + "a5_4",
    "east" : ROOMO + "a7_4"
  ]));
}
