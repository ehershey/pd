#include <std.h>
#include <arlon2.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

  set_exits(([
    "south" : ROOMS + "roads/17.c",
    "north" : "/d/nopk/arlon_path/22,30,0.c"
  ]));
}
