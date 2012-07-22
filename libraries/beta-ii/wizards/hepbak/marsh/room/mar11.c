#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();

    set_exits( ([
"northwest" : ROOMS "mar15",
"north" : ROOMS "mar16",
"west" : ROOMS "mar10",
"east" : ROOMS "mar12",
    ]) );

}
