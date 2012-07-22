// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "northwest": ROOMS"elven_path_22.c",
               "northeast": ROOMS"elven_path_23.c",
               "southwest": ROOMS"elven_path_27.c",
  ]) );
}
