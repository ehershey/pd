#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "southwest" : ROOMS"room45",
                "east" : ROOMS"room41",
                "northwest" : ROOMS"room43",

                

  ]) );
}
