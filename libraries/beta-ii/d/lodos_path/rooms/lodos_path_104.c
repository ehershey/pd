// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_93.c",
                "north": ROOMS"lodos_path_94.c",
                "south": ROOMS"lodos_path_114.c",
  ]) );
}
