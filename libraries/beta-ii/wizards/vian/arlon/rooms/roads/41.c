#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/40.c",
    "east" : ROOMS + "roads/42.c",
    "enter north house" : ROOMS + "houses/47.c",
    "enter south house" : ROOMS + "houses/46.c",
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
