// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_332.c",
                "northeast": ROOMS"lodos_path_333.c",
                "east": ROOMS"lodos_path_339.c",
                "south": ROOMS"lodos_path_344.c",
  ]) );
}
