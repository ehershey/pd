// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_256.c",
                "northwest": ROOMS"lodos_path_246.c",
                "southeast": ROOMS"lodos_path_268.c",
  ]) );
}
