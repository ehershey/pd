#include <std.h>
#include <forserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"north" : FOR "a51",
"south" : FOR "a46",
    ]) );
}
