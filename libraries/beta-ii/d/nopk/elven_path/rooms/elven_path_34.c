// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "northeast": ROOMS"elven_path_31.c",
               "south": ROOMS"elven_path_38.c",
  ]) );
}
