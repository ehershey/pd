#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : SAB "sab60",
"west" : SAB "sab55",
    ]) );
}
