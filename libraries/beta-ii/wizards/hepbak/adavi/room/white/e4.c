#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : WHITE "e5",
"south" : WHITE "e",
    ]) );
}