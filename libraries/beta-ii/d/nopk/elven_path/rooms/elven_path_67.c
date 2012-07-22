// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "north": ROOMS"elven_path_64.c",
               "east": ROOMS"elven_path_68.c",
               "southwest": ROOMS"elven_path_70.c",
  ]) );
}
