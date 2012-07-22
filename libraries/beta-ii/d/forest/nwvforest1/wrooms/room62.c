#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northwest" : WROOMS"room66",
                "northeast" : WROOMS"room67",
                "southeast" : WROOMS"room55",
  ]) );
}
