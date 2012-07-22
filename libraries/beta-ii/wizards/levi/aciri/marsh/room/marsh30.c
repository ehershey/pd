#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "south" : ROOMS "marsh22.c",
                "north" : ROOMS "marsh36.c", ]) );
}  
