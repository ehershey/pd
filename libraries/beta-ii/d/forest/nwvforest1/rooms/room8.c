#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "northeast" : ROOMS"room11", 
                "north" : ROOMS"room10",
                "south" : ROOMS"room4",
  ]) );
}
