#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest" : ROOMS"room3",
                "north" : ROOMS"room5",
                "south" : ROOMS"room10",
                

  ]) );
}