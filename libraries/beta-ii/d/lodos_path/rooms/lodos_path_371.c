// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_370.c",
                "north": ROOMS"lodos_path_367.c",
                "east": ROOMS"lodos_path_372.c",
  ]) );
}
