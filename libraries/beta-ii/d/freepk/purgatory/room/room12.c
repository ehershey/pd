
#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest" : ROOMS"room11",
                "east" : ROOMS"room13",
                

  ]) );
}
