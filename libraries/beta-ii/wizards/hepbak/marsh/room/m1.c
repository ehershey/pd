#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m2",
"east" : ROOMS "marsh22",
    ]) );
}
