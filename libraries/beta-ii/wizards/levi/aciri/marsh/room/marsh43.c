#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northeast" : ROOMS "marsh51.c",
		"west" : ROOMS "marsh42.c", ]) );
}  
