#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh7",
"west" : ROOMS "marsh3",
"southwest" : ROOMS "marsh",
"northwest" : ROOMS "marsh6",
    ]) );

}
