// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_345.c",
                "north": ROOMS"lodos_path_341.c",
                "southeast": ROOMS"lodos_path_352.c",
  ]) );
}
