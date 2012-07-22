#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

    set_exits( ([
"south" : ROOMS "mar9",
"north" : ROOMS "mar17",
"northeast" : ROOMS "mar18",
"east" : ROOMS "mar15",
"west" : ROOMS "mar13",
"southwest" : ROOMS "mar8",
    ]) );

}
