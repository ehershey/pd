#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "northwest" : ROOMS "marsh9.c",
	        "northeast" : ROOMS "marsh10.c" ]) );
}  
