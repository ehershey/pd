#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : SAB "sab47",
"east" : SAB "sab56",
"west" : SAB "sab54",
    ]) );
}

