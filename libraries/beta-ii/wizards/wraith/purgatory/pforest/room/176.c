#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "northeast" : ROOMS"175",
                "southeast" : ROOMS"177",
                 
  ]) );
}

