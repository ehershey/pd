#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

                "northwest" : ROOMS"154",
                "southwest" : ROOMS"160",
                "south" : ROOMS"156",


  ]) );
}

