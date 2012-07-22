// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_189.c",
                "north": ROOMS"lodos_path_190.c",
                "southeast": ROOMS"lodos_path_213.c",
  ]) );
}
