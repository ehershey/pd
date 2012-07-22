// Made by Stormy 7/18/2004
#include <std.h>
#include <elven_path.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
               "north": "/d/nopk/standard/rain_forest/corinthor/rooms/entry1",
               "south": ROOMS"elven_path_2.c",
               "southwest": ROOMS"elven_path_1.c",
  ]) );
}
