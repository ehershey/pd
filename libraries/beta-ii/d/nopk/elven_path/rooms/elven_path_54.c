// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "north": ROOMS"elven_path_51.c",
               "southeast": ROOMS"elven_path_58.c",
               "south": ROOMS"elven_path_57.c",
  ]) );
}
