#include <std.h>
#include <pastarlon.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROADSERVER);
  ::create();
  set_exits(([
    "south" : ROOMS + "roads/37.c",
    "east" : ROOMS + "roads/39.c",
    "enter north house" : ROOMS + "houses/116.c",
  ]));
add_exit_alias("enter north house", "north house");
add_exit_alias("enter north house", "enter north house");
add_exit_alias("enter north house", "north");
add_exit_alias("enter north house", "n");
}

