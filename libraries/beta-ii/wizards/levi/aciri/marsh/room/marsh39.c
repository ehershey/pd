#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northwest" : ROOMS "marsh48.c",
		"east" : ROOMS "marsh40.c", ]) );
}  
