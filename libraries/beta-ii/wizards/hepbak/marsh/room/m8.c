#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "m11",
"east" : ROOMS "m9",
"southwest" : ROOMS "m6",
    ]) );
}