#include <std.h>
#include <arlon2.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
  set_exits(([
    "north" : ROOMS + "roads/36.c",
    "east" : ROOMS + "roads/34.c",
    "enter south house" : ROOMS + "houses/117.c",
  ]));
add_exit_alias("enter south house", "south house");
add_exit_alias("enter south house", "enter south house");
add_exit_alias("enter south house", "south");
add_exit_alias("enter south house", "s");
}
