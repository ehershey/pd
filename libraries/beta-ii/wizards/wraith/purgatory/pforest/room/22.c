#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 


                "north" : ROOMS"21",

                "northeast" : ROOMS"23",



  ]) );
}


