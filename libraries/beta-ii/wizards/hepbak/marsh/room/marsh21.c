#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northeast" : ROOMS "marsh26",
"west" : ROOMS "marsh20",
"south" : ROOMS "marsh16",
"north" : ROOMS "marsh25",
"northwest" : ROOMS "marsh24",
"southwest" : ROOMS "marsh15",
    ]) );

}
