#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : MARSH "b",
"southwest" : MARSH "mar24",
    ]) );
}
