#include <std.h>
#include <forserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : FOR "a32",
"east" : FOR "a22",
    ]) );
}
