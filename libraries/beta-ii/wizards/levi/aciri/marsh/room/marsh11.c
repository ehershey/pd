#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "east" : ROOMS "marsh12.c",
                "northwest" : ROOMS "marsh16.c",
	        "southwest" : ROOMS "marsh8.c", ]) );
}  
