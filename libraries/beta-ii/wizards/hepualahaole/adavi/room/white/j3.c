#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"northwest" : WHITE "j5",
"north" : WHITE "j6",
    ]) );
}
