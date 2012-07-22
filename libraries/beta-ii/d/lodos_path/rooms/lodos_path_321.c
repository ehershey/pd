// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_320.c",
                "north": ROOMS"lodos_path_311.c",
                "east": ROOMS"lodos_path_322.c",
  ]) );
}
