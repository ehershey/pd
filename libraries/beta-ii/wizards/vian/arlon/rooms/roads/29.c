#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "roads/30.c",
    "north" : ROOMS + "roads/5.c",
    "enter east house" : ROOMS + "houses/110.c",
  ]));
add_exit_alias("enter east house", "east house");
add_exit_alias("enter east house", "enter east house");
add_exit_alias("enter east house", "east");
add_exit_alias("enter east house", "e");
}
