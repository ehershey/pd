// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest": ROOMS"lodos_path_280.c",
                "northeast": ROOMS"lodos_path_281.c",
                "south": ROOMS"lodos_path_300.c",
  ]) );
}