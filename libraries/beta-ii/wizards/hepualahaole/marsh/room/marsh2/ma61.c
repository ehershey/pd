#include <std.h>
#include <marserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : MARSH2 "ma57",
"north" : MARSH "m29",
"northeast" : GRASS "g11",
    ]) );
}