#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : MARSH "m2",
"east" : MARSH "marsh22",
    ]) );
}
