// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "west": ROOMS"elven_path_72.c",
               "northeast": ROOMS"elven_path_70.c",
               "south": ROOMS"elven_path_76.c",
  ]) );
}
