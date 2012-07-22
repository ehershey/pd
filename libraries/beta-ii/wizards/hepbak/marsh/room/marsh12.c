#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh15",
"southwest" : ROOMS "marsh8",
"northeast" : ROOMS "marsh16",
"northwest" : ROOMS "marsh14",
"west" : ROOMS "marsh11",
    ]) );
}
