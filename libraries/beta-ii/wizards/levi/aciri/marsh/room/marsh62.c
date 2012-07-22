#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "south" : ROOMS "marsh60.c",
		"northeast" : ROOMS "marsh63.c" ]) );
}  
