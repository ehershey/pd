#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/42.c",
    "south" : ROOMS + "roads/28.c",
    "enter east house" : ROOMS + "houses/114.c",
    "enter north house" : ROOMS + "houses/115.c",
  ]));
add_exit_alias("enter east house", "east house");
add_exit_alias("enter east house", "enter east house");
add_exit_alias("enter east house", "east");
add_exit_alias("enter east house", "e");
add_exit_alias("enter north house", "north house");
add_exit_alias("enter north house", "enter north house");
add_exit_alias("enter north house", "north");
add_exit_alias("enter north house", "n");
}
