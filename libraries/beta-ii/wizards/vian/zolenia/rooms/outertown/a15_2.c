#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "west" : ROOMO + "a14_2",
    "east" : ROOMO + "a16_2"
  ]));
}