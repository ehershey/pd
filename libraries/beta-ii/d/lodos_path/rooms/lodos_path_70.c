// Made by Stormy 7/11/2004
#include <std.h>
#include <lodospath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west": ROOMS"lodos_path_69.c",
                "northeast": ROOMS"lodos_path_58.c",
                "southeast": ROOMS"lodos_path_83.c",
                "south": ROOMS"lodos_path_82.c",
  ]) );
}
