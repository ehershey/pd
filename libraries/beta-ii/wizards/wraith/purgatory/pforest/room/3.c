#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "north" : ROOMS"4",

                "northwest" : ROOMS"2", 

  ]) );
}
