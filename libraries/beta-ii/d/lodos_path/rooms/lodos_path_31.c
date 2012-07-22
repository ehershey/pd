// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_30.c",
                "northeast": ROOMS"lodos_path_21.c",
                "south": ROOMS"lodos_path_44.c",
  ]) );
}
