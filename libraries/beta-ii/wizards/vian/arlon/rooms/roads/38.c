#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "roads/37.c",
    "east" : ROOMS + "roads/39.c",
    "a large manor" : ROOMS + "phouses/kilir/1.c",
  ]));
add_exit_alias("a large manor", "a large manor");
add_exit_alias("a large manor", "large manor");
add_exit_alias("a large manor", "manor");
add_exit_alias("a large manor", "north");

}
