#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : ROOMS "mar10",
"north" : ROOMS "mar18",
"northwest" : ROOMS "mar17",
"east" : ROOMS "mar16",
"west" : ROOMS "mar14",
"southeast" : ROOMS "mar11",
    ]) );

}
