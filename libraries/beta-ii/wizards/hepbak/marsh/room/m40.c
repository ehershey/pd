#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "m39",
"south" : ROOMS "m33",
    ]) );
}
