#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : ROOMS "mar21",
"west" : ROOMS "mar23",
    ]) );
}
