#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 



                "south" : ROOMS"67",
                "southeast" : ROOMS"79",
                "east" : ROOMS"69",

  ]) );
}
