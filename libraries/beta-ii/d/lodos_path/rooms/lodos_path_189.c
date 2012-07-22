// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_179.c",
                "north": ROOMS"lodos_path_180.c",
                "southeast": ROOMS"lodos_path_201.c",
                "south": ROOMS"lodos_path_200.c",
  ]) );
}
