
#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 


                "north" : ROOMS"25",
                "south" : ROOMS"23",
                "northeast" : ROOMS"32",



  ]) );
}
