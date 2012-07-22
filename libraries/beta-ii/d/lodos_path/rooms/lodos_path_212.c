// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_199.c",
                "northeast": ROOMS"lodos_path_200.c",
                "south": ROOMS"lodos_path_223.c",
  ]) );
}
