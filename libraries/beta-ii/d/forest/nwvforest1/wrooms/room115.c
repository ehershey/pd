#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([
                "southeast" : WROOMS"room110",
                "west" : WROOMS"room114",
  ]) );
}
