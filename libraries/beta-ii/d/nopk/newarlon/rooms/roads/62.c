#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
set_long(query_long(0) + " A large warehouse can be seen to the east.");
  set_exits(([
    "south" : ROOMS + "roads/63.c",
    "east" : ROOMS + "warehouse.c",
    "north" : ROOMS + "roads/61.c"
  ]));
}
