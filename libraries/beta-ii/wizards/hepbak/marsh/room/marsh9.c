#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "marsh5",
"northwest" : ROOMS "marsh11",
"west" : ROOMS "marsh8",
"south"  : ROOMS "marsh6",
"southeast" : ROOMS "marsh7",
    ]) );
}
