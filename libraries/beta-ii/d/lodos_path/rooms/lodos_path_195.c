// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north": ROOMS"lodos_path_184.c",
                "east": ROOMS"lodos_path_196.c",
                "southeast": ROOMS"lodos_path_206.c",
  ]) );
}
