#include <std.h>
#include <marshserver.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits( ([
"southeast" : ROOMS "mar17",
"east" : ROOMS "mar20",
    ]) );
  }
