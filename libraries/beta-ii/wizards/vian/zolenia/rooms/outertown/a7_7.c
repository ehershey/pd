#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "northeast" : ROOMO + "a8_6",
    "west" : ROOMO + "a6_7"
  ]));
}