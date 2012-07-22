// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_151.c",
                "northwest": ROOMS"lodos_path_141.c",
                "east": ROOMS"lodos_path_153.c",
                "southeast": ROOMS"lodos_path_165.c",
                "southwest": ROOMS"lodos_path_164.c",
  ]) );
}
