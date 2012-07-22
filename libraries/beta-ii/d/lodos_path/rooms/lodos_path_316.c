// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_315.c",
                "northwest": ROOMS"lodos_path_305.c",
                "east": ROOMS"lodos_path_317.c",
                "south": ROOMS"lodos_path_325.c",
  ]) );
}
