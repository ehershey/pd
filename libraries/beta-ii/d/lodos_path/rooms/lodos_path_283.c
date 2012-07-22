// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_270.c",
                "northeast": ROOMS"lodos_path_271.c",
                "southeast": ROOMS"lodos_path_293.c",
  ]) );
}
