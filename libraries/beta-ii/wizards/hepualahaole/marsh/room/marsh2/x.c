#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : MARSH2 "w",
"north" : MARSH "m10",
    ]) );
}
