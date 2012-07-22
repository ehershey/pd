#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "west" : ROOMS + "roads/38.c",
    "east" : ROOMS + "roads/40.c",
    "enter north house" : ROOMS + "houses/50.c",
    "enter south house" : ROOMS + "houses/51.c",
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
