#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "north" : WROOMS"room61",
                "south" : WROOMS"room48",
  ]) );
}
