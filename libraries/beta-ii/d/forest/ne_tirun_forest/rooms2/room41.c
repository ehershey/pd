#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "southwest" : WROOMS"room37",
                "southeast" : WROOMS"room36",
                "north" : WROOMS"room46",
  ]) );
}
