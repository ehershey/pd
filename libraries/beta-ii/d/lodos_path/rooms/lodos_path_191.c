// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_181.c",
                "east": ROOMS"lodos_path_192.c",
                "southeast": ROOMS"lodos_path_202.c",
  ]) );
}
