// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_130.c",
                "northwest": ROOMS"lodos_path_116.c",
                "east": ROOMS"lodos_path_132.c",
                "southeast": ROOMS"lodos_path_142.c",
  ]) );
}
