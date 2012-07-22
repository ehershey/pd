#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/31.c",
    "north" : ROOMS + "roads/29.c",
    "enter east house" : ROOMS + "houses/111.c",
    "enter south house" : ROOMS + "houses/112.c",
  ]));
add_exit_alias("enter east house", "east house");
add_exit_alias("enter east house", "enter east house");
add_exit_alias("enter east house", "east");
add_exit_alias("enter east house", "e");
add_exit_alias("enter south house", "south house");
add_exit_alias("enter south house", "enter south house");
add_exit_alias("enter south house", "south");
add_exit_alias("enter south house", "s");
}
