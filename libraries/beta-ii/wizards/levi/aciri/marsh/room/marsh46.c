#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh47.c",
		"northwest" : ROOMS "marsh52.c",
		"west" : ROOMS "marsh45.c", ]) );
}  
