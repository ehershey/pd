#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

               "southwest" : ROOMS"198",
               "northwest" : ROOMS"196",

  ]) );
}
