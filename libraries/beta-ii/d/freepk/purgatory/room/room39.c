#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north" : ROOMS"room38",
                "northeast" : ROOMS"room40",

                

  ]) );
}