#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "southwest" : ROOMS"room60",
                "south" : ROOMS"room62",

                

  ]) );
}

