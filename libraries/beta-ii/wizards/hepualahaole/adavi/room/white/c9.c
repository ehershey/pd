#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : WHITE "c8",
"south" : WHITE "c6",
    ]) );
}
