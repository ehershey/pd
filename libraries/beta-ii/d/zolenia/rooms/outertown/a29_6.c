#include <std.h>
#include <zolenia.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "northwest" : ROOMO + "a28_5",
    "west" : ROOMO + "a28_6",
    "east" : ROOMO + "a30_6"
  ]));
}