#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m20",
"southeast" : ROOMS "m13",
"south" : ROOMS "m12",
    ]) );
}
