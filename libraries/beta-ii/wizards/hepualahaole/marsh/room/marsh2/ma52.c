#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : MARSH2 "ma58",
"south" : MARSH2 "ma41",
    ]) );
}
