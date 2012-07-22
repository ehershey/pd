#include <std.h>
#include <marsha.h>

inherit VIRTUALROOM;

void create() {
  set_server(ROOMS "marshserver");
  ::create();
  set_exits( ([ "southwest" : ROOMS "marsh4.c",
                "northeast" : ROOMS "marsh15.c",
	        "south" : ROOMS "marsh5.c", ]) );
}  
