#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "south" : ROOMS"3",
                "southwest" : ROOMS"5", 

  ]) );
}
