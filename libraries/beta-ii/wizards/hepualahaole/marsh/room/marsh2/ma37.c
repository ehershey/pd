#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : MARSH2 "ma29",
"east" : MARSH2 "ma38",
"northwest" : MARSH2 "ma47",
    ]) );
}
