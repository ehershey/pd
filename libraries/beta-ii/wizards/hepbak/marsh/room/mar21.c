#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "mar24",
"east" : ROOMS "mar22",
"west" : ROOMS "mar20",
    ]) );

}
