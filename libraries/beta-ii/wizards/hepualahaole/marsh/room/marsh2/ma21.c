#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : MARSH2 "ma28",
"southeast" : MARSH2 "ma21",
    ]) );
}
