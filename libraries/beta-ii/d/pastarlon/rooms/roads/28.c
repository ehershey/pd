#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "roads/5.c",
    "north" : ROOMS + "roads/43.c",
    "enter east house" : ROOMS + "houses/113.c",
  ]));
add_exit_alias("enter east house", "east house");
add_exit_alias("enter east house", "enter east house");
add_exit_alias("enter east house", "east");
add_exit_alias("enter east house", "e");
}
