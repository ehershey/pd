// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_318.c",
                "northwest": ROOMS"lodos_path_307.c",
                "north": ROOMS"lodos_path_308.c",
                "southeast": ROOMS"lodos_path_327.c",
                "south": ROOMS"lodos_path_326.c",
  ]) );
}
