#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : MARSH2 "ma60",
"west" : MARSH2 "ma54",
    ]) );
}
