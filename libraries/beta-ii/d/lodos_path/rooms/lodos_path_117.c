// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northeast": ROOMS"lodos_path_107.c",
                "southwest": ROOMS"lodos_path_132.c",
  ]) );
}
