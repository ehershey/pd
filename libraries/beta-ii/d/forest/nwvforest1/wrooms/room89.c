#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "north" : WROOMS"room96",
                "southwest" : WROOMS"room83",
  ]) );
}
