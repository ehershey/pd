#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : WHITE "k3",
"north" : WHITE "k9",
    ]) );
}
