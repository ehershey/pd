#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : WHITE "e14",
"south" : WHITE "e13",
    ]) );
}