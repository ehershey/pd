#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

                "northwest" : ROOMS"90",
                "southwest" : ROOMS"89",
                "northeast" : ROOMS"179",
  ]) );
}
