// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "west": ROOMS"elven_path_9.c",
               "northeast": ROOMS"elven_path_8.c",
  ]) );
}
