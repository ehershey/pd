
#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

                "north" : ROOMS"124",
                "south" : ROOMS"122",

  ]) );
}
