#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "northeast" : WROOMS"room80",
                "southwest" : WROOMS"room68",
  ]) );
}
