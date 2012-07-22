#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest" : ROOMS"room18",
                "northeast" : ROOMS"room19",
                "south" : ROOMS"room39",
                

  ]) );
}
