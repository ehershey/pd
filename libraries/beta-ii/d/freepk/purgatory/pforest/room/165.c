#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

                "northwest" : ROOMS"164",
                "southwest" : ROOMS"166",

  ]) );
}
