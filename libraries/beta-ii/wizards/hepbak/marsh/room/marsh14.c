#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
       "north" : ROOMS "marsh19",
       "northeast" : ROOMS "marsh20",
       "northwest" : ROOMS "marsh18",
       "south" : ROOMS "marsh11",
       "east" : ROOMS "marsh15",
       "west" : ROOMS "marsh13",
    ]) );
}
