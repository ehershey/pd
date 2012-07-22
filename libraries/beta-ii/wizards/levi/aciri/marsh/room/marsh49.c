#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southwest" : ROOMS "marsh41.c",
		"northwest" : ROOMS "marsh54.c" ]) );
}  
