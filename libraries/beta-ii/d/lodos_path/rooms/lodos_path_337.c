// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northeast": ROOMS"lodos_path_332.c",
                "south": ROOMS"lodos_path_343.c",
  ]) );
}
