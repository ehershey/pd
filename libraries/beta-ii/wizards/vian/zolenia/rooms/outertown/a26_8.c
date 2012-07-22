#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "northwest" : ROOMO + "a25_7",
    "east" : ROOMO + "a27_8"
  ]));
}
