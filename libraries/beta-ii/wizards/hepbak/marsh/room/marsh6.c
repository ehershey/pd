#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : ROOMS "marsh9",
"east" : ROOMS "marsh7",
"southeast" : ROOMS "marsh4",
"northwest" : ROOMS "marsh8",
"south" : ROOMS "marsh3",
"southwest" : ROOMS "marsh2",
"west"  : ROOMS "marsh5",
    ]) );
}
