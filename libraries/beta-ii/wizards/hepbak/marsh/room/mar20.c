#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "mar23",
"east" : ROOMS "mar21",
"west" : ROOMS "mar19",
    ]) );

}
