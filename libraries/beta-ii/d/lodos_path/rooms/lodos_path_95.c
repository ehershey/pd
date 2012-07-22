// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_83.c",
                "east": ROOMS"lodos_path_96.c",
                "south": ROOMS"lodos_path_105.c",
  ]) );
}
