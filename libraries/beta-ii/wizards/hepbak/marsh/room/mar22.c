#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "mar18",
"west" : ROOMS "mar21",
    ]) );
}
