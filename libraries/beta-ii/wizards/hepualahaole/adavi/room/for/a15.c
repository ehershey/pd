#include <std.h>
#include <forserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"east" : FOR "a16",
"west" : FOR "a14",
    ]) );
}