#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : MARSH2 "ma17",
"south" : MARSH2 "ma7",
    ]) );
}
