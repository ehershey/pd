#include <std.h>
#include <forserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : FOR "a25",
"south" : FOR "a12",
    ]) );
}
