// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "northwest": ROOMS"elven_path_12.c",
               "northeast": ROOMS"elven_path_13.c",
               "southeast": ROOMS"elven_path_17.c",
               "southwest": ROOMS"elven_path_16.c",
  ]) );
}
