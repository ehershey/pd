#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "south" : ROOMS"room24", 
                "north" : ROOMS"room26",

  ]) );
}
