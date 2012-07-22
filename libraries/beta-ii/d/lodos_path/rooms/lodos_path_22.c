// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_14.c",
                "northeast": ROOMS"lodos_path_15.c",
                "south": ROOMS"lodos_path_33.c",
  ]) );
}
