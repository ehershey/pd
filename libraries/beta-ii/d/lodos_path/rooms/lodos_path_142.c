// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_131.c",
                "east": ROOMS"lodos_path_143.c",
                "southwest": ROOMS"lodos_path_153.c",
  ]) );
}
