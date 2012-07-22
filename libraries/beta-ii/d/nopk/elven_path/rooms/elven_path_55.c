// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "north": ROOMS"elven_path_52.c",
               "southeast": ROOMS"elven_path_59.c",
               "southwest": ROOMS"elven_path_58.c",
  ]) );
}
