#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "west" : WROOMS"room2", 
                "northeast" : WROOMS"room4",
  ]) );
}
