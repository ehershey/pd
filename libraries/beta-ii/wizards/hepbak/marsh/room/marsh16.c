#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh21",
"northwest" : ROOMS "marsh20",
"west" : ROOMS "marsh15",
"southwest" : ROOMS "marsh12",
    ]) );

}
