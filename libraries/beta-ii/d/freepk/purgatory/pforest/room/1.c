#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "southeast" : "/d/freepk/purgatory/room/beach4",
                "northwest" : ROOMS"6",
                "northeast" : ROOMS"2",
  ]) );
}
