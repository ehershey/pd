#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : SAB "sab49",
"west" : SAB "sab47",
    ]) );
}
