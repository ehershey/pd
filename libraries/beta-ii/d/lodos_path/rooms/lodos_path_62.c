// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_61.c",
                "northwest": ROOMS"lodos_path_50.c",
                "southeast": ROOMS"lodos_path_72.c",
  ]) );
}
