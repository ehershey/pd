#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/11.c",
    "east" : "/d/nopk/arlon_zoo/rooms/arlonroad5",
  ]));
}
