#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "south" : ROOMS"room40",
                "northeast" : ROOMS"room54",
  ]) );
}
