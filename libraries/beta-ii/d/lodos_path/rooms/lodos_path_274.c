// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north": ROOMS"lodos_path_261.c",
                "northeast": ROOMS"lodos_path_262.c",
                "east": ROOMS"lodos_path_275.c",
                "southwest": ROOMS"lodos_path_285.c",
  ]) );
}
