#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"south" : MARSH "mar20",
"east" : MARSH "mar24",
    ]) );
}
