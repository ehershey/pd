#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : WHITE "h11",
"north" : WHITE "h13",
    ]) );
}
