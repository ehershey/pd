#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/34.c",
    "east" : ROOMS + "roads/32.c",
    "enter north house" : ROOMS + "houses/54.c",
    "enter south house" : ROOMS + "houses/55.c",
  ]));
add_exit_alias("enter north house", "north house");
add_exit_alias("enter north house", "enter north house");
add_exit_alias("enter north house", "north");
add_exit_alias("enter north house", "n");
add_exit_alias("enter south house", "south house");
add_exit_alias("enter south house", "enter south house");
add_exit_alias("enter south house", "south");
add_exit_alias("enter south house", "s");
}