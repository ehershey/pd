#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : MARSH "mar",
"southwest" : MARSH "marsh26",
"northeast" : MARSH "mar8",
    ]) );
}
