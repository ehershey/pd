// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "west": ROOMS"elven_path_83.c",
               "northeast": ROOMS"elven_path_82.c",
               "south": ROOMS"elven_path_86.c",
  ]) );
}
