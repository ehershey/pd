// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north": ROOMS"lodos_path_373.c",
                "up": "/d/tirunmts/rooms/tirunmts_69.c",
  ]) );
}
