#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"west" : ROOMS "m31",
"southwest" : ROOMS "m26",
"north" : ROOMS "m38",
    ]) );
}