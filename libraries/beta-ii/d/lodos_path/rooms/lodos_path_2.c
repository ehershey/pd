// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "east": ROOMS"lodos_path_3.c",
                "southwest": ROOMS"lodos_path_13.c",
  ]) );
}