#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northeast" : WROOMS"room72",
                "southwest" : WROOMS"room61",
                "southeast" : WROOMS"room62",
  ]) );
}
