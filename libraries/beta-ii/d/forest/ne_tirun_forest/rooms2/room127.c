#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "west" : ROOMS"room15",
                "east" : WROOMS"room128",
  ]) );
}
