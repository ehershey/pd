// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_182.c",
                "southeast": ROOMS"lodos_path_194.c",
                "south": ROOMS"lodos_path_193.c",
  ]) );
}
