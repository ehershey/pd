#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "southwest" : ROOMO + "a2_5",
    "east" : ROOMO + "a4_4"
  ]));
}
