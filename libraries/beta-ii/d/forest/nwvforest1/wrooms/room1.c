#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : WROOMS"room2", 
"southwest" : "/d/nopk/forest/tiruneastforest/rooms/tiruneastforest104",
  ]) );
}
