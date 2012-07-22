// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north": ROOMS"lodos_path_286.c",
                "southeast": ROOMS"lodos_path_307.c",
                "southwest": ROOMS"lodos_path_306.c",
  ]) );
}
