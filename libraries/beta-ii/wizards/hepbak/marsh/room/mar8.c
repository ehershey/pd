#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "mar13",
"southwest" : ROOMS "mar6",
"northeast" : ROOMS "mar14",
"east" : ROOMS "mar9",
    ]) );

}
