#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : WHITE "j14",
"east" : WHITE "j12",
    ]) );
}