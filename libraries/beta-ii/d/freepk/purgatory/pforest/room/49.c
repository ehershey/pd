#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 





                "southeast" : ROOMS"48",
                "southwest" : ROOMS"50",




  ]) );
}

