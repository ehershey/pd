#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southwest" : ROOMS "marsh3",
"northwest" : ROOMS "marsh9",
"south" : ROOMS "marsh4",
"west"  : ROOMS "marsh6",
    ]) );

}
