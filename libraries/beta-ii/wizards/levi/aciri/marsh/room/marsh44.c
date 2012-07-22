#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northeast" : ROOMS "marsh52.c",
                "northwest" : ROOMS "marsh51.c",
                "east" : ROOMS "marsh45.c",
		"south" : ROOMS "marsh37.c", ]) );
}  
