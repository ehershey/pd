#include <std.h>
#include <whiteserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : WHITE "j15",
"west" : WHITE "j17",
    ]) );
}