#include <std.h>
#include <sabserver.h>
inherit DESERT;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : SAB "sab31",
"south" : SAB "sab17",
    ]) );
}

