#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : MARSH "m5",
"south" : MARSH "m2",
    ]) );
}
