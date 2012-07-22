#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "roads/37.c",
    "east" : ROOMS + "roads/39.c",
    "enter manor" : ROOMS + "phouses/kilir/1.c",
  ]));
add_exit_alias("enter manor", "manor");
add_exit_alias("enter manor", "north");

}
