#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : WHITE "d9",
"west" : WHITE "d5",
"south" : WHITE "d3",
    ]) );
}