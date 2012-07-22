#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "southeast" : ROOMS"room30", 
                "west" : ROOMS"room22",

  ]) );
}
