#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m4",
"south" : ROOMS "m1",
    ]) );
}
