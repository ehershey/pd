// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "northwest": ROOMS"elven_path_48.c",
               "northeast": ROOMS"elven_path_49.c",
               "southeast": ROOMS"elven_path_56.c",
               "south": ROOMS"elven_path_55.c",
  ]) );
}
