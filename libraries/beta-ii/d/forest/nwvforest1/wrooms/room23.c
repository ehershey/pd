#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : WROOMS"room24",
                "southwest" : WROOMS"room19",
  ]) );
}
