// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_118.c",
                "northeast": ROOMS"lodos_path_108.c",
                "east": ROOMS"lodos_path_120.c",
                "south": ROOMS"lodos_path_134.c",
                "southwest": ROOMS"lodos_path_133.c",
  ]) );
}
