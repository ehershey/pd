#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "southeast" : ROOMO + "a10_3",
    "west" : ROOMO + "a8_2"
  ]));
}
