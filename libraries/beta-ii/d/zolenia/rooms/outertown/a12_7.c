#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "southwest" : ROOMO + "a11_8",
    "east" : ROOMO + "a13_7"
  ]));
}
