#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m35",
"east" : ROOMS "m28",
    ]) );
}
