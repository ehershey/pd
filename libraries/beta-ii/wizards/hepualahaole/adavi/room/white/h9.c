#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : WHITE "h8",
"southwest" : WHITE "h5",
    ]) );
}
