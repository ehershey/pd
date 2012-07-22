// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_102.c",
                "northeast": ROOMS"lodos_path_103.c",
                "southeast": ROOMS"lodos_path_124.c",
  ]) );
}
