#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : MARSH2 "z2",
"north" : MARSH2 "h",
"south" : MARSH2 "t2",
    ]) );
}
